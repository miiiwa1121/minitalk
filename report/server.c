/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:31 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/22 16:11:02 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_handler(int signal)
{
	//1bitずつ受信して1バイトそろった時点で文字に変換するため、static変数を使用
	static int	bit;//処理中のビットの位置を保持
	static int	c;//受信中の文字のビット情報を保持

	if (signal == SIGUSR1)//ビットが１の場合
		c |= (1 << bit);//cに１を追加(bit 番目のビットを 1 にする ためのビット操作)

	bit++;//次のビットに移動 & ビット数をカウント

	if (bit == 8)//８ビット分の処理が終わったら
	{
		write(1, &c, 1);//cに蓄積した８ビット分にバイナリを文字として出力(標準出力、メモリアドレス、1バイト(8ビット))
		bit = 0;//リセット
		c = 0;//リセット
	}
}

int	main(int ac, char **av)
{
		struct sigaction sa;//シグナル処理の設定を保持する構造体

	(void)av;//このプログラムはサーバー側のプログラムであるため、引数は不要(未使用の引数を無視)
	if (ac != 1)
		error_handler("Invalid arguments", "Usage: ./server");//[./server]のみ受け付ける

	ft_printf("Server PID: %d\n", getpid());//サーバーのプロセスIDを表示

	//シグナル処理の設定を初期化	
	sa.sa_flags = 0;
//シグナルハンドリングの動作に関するオプションを設定するフィールドです。
//このコードでは、sa_flags を 0 に設定して、特にフラグを設定していません。
//これにより、デフォルトの挙動（シグナルが同期的に処理される）を使用することになります。
//もし特別な動作（例えば、非同期処理や再起動など）を希望する場合は、この値を変更します

//シグナルハンドラの設定
	sa.sa_handler = signal_handler;//SIGUSR1とSIGUSR2のシグナルを受信した際にsignal_handler関数を実行するように設定

	sigemptyset(&sa.sa_mask);//シグナル処理の設定（シグナルマスク）を初期化
//シグナルマスクは、シグナルがハンドラによって処理される間に他のシグナルが受け取られることを防ぐために使用されます。
//sigemptysetは、このマスクを「空」にする関数であり、初期化して他のシグナルがハンドラによってブロックされないように設定しています。
//初期化しないと、デフォルトで設定されているシグナルマスクの状態（どのシグナルがブロックされるかが不確定）に依存することになります。
	
//SIGUSR1とSIGUSR2をブロックする
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 || sigaddset(&sa.sa_mask, SIGUSR2) == -1)//シグナルマスクにSIGUSR1とSIGUSR2を追加(-1はエラー)
		error_handler("Sigaddset error", NULL);//sigaddsetが上手くいかなった場合はエラーメッセージを表示してプログラムを終了
//シグナルマスクに追加することで、signal_handler が SIGUSR1 と SIGUSR2 のシグナルを処理している間、それらのシグナルが再度発生しても無視されるようにします。
//これにより、シグナルが連続して送られた場合でも、処理中に他のシグナルが混入して予期しない動作をするのを防ぎます。
//SIGUSR1を受信してシグナルハンドラが実行されている間に、SIGUSR2が発生しても、SIGUSR2は無視されます。そのため、受信するタイミングや順番が大切になる

//シグナル処理の設定を有効にする
	if (sigaction(SIGUSR1, &sa, NULL) == -1	|| sigaction(SIGUSR2, &sa, NULL) == -1)//SIGUSR1とSIGUSR2のシグナル処理を設定(-1はエラー)
		error_handler("Sigaction error", NULL);//sigactionが上手くいかなかった場合はエラーメッセージを表示してプログラムを終了
//受信されたときに signal_handler 関数が呼ばれるように設定

//無限ループ
	while (1)
	{
		pause();//シグナルを受信するまで待機
		usleep(WAIT_TIME);//WAIT_TIME分だけ待機//この間にハンドラ処理を終わらせる
	}
	return (0);
}

