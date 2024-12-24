# Minitalk

## Project Structure
```
.
├── Makefile
├── all_libft
│   ├── Makefile
│   ├── include
│   │   ├── ft_printf.h
│   │   ├── get_next_line_bonus.h
│   │   └── libft.h
│   └── src
│       ├── ft_printf
│       ├── gnl
│       └── libft
│           ├── bool_atoi.c
│           ├── error_handler.c
│           ├── ft_isspace.c
├── include
│   ├── minitalk.h
│   └── minitalk_bonus.h
└── src
    ├── client.c
    ├── client_bonus.c
    ├── server.c
    └── server_bonus.c

8 directories, 66 files
```

## Build and Clean Commands
### Build
- Build all: `make`
- Build with bonus: `make bonus`

### Clean
- Remove intermediate files: `make clean`
- Complete cleanup: `make fclean`

### Rebuild
- Rebuild everything: `make re`

---

## Key Concepts and Commands

### Commands
- **`kill`**: Sends a signal to a specified process.
- **`error_handler`**: Handles errors and displays messages within the program.
- **`usleep`**: Pauses program execution for a specified time in microseconds.
- **`getpid`**: Retrieves the process ID (PID) of the current process.
- **`sigemptyset`**: Initializes a signal mask (signal set) to be empty.
- **`sigaddset`**: Adds a specific signal to the signal mask.
- **`sigaction`**: Sets up a handler for specific signals.
- **`pause`**: Suspends the program until a signal is received.

### Terminology
- **PID**: A unique identifier assigned to each process by the operating system.
- **Signal**: A mechanism used in UNIX/Linux environments for inter-process communication or to notify a process about an event. Signals act as software interrupts.
- **System Call**: An interface through which user programs request services from the operating system kernel. Examples include file operations, process management, and network communication.
- **Signal Mask**: A mechanism to temporarily block specific signals from being delivered to a process.

---

## Notes
### Signals
Signals are a form of software interrupt in UNIX/Linux used for process communication or system notifications. For example, a signal can notify a process that a child process has terminated or that an error occurred.

### System Calls
System calls provide an interface for user-level programs to request OS kernel services, such as accessing files, managing processes, or performing I/O operations.

### Signal Mask
Signal masks are used to block specific signals temporarily, ensuring critical sections of code execute without interruptions.

---

## Questions
### Client Code
```c
if ((c & (1 << bit)) != 0):
```
- Question: What is the purpose of this condition in checking the bits of a character?

### Server Code
```c
c |= (1 << bit);
```
- Question: How does this line reconstruct the character from received signal bits?

---

Feel free to contribute to or ask questions about the project!

# Minitalk (日本語版)

## ビルドとクリーンコマンド
### ビルド
- 全ビルド: `make`
- ボーナス付きビルド: `make bonus`

### クリーン
- 中間ファイル削除: `make clean`
- 完全クリーンアップ: `make fclean`

### 再ビルド
- 全て再ビルド: `make re`

---

## 主要な概念とコマンド

### コマンド
- **`kill`**: 指定されたプロセスにシグナルを送信します。
- **`error_handler`**: プログラム内でエラーが発生した際に処理とメッセージ表示を行う関数。
- **`usleep`**: プログラムの実行を指定時間（マイクロ秒単位）停止します。
- **`getpid`**: 現在のプロセスID（PID）を取得します。
- **`sigemptyset`**: シグナルマスク（シグナルセット）を空に初期化します。
- **`sigaddset`**: シグナルマスクに特定のシグナルを追加します。
- **`sigaction`**: 特定のシグナルを受信した際のハンドラーを設定します。
- **`pause`**: シグナルを受信するまでプログラムを一時停止します。

### 用語
- **PID**: OSが各プロセスを一意に識別するために割り当てる番号。
- **シグナル**: UNIX/Linux環境でプロセス間通信やイベント通知を行う仕組み。ソフトウェア割り込みとして動作します。
- **システムコール**: ユーザープログラムがOSのカーネル機能を利用するためのインターフェース。例: ファイル操作、プロセス管理、ネットワーク通信。
- **シグナルマスク**: 特定のシグナルを一時的にブロック（受信しないように）する仕組み。

---

## メモ
### シグナル
シグナルは、UNIX/Linuxにおけるソフトウェア割り込みの一種で、プロセス間の通信やシステムからプロセスへの通知に使用されます。例えば、子プロセスの終了通知やエラーの通知などに利用されます。

### システムコール
システムコールは、ユーザープログラムがOSカーネルのサービスを要求するインターフェースで、ファイルアクセスやプロセス管理、入出力操作を実現します。

### シグナルマスク
シグナルマスクを使うことで、特定のシグナルを一時的にブロックし、重要なコードが中断されることを防ぎます。

---

## 質問
### クライアントコード
```c
if ((c & (1 << bit)) != 0):
```
- 質問: この条件式は、文字のビットをどのようにチェックしているのですか？

### サーバーコード
```c
c |= (1 << bit);
```
- 質問: この行は、受信したシグナルビットから文字をどのように再構成しているのですか？

---

プロジェクトに関する質問や貢献をお待ちしています！

