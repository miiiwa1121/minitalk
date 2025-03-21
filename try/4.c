/* 
write関数がUTF8を自動で感知していることの確認

c = (unsigned char)0b11100011; 
write(1, &c, 1);//本来ならばここの時点でなにか表示してそうだが、この時点では何も表示されない
c = (unsigned char)0b10000010;
write(1, &c, 1);
c = (unsigned char)0b10100010;
write(1, &c, 1); // この時点で3バイト分感知し、なにかの文字になったことで画面に表示されている

これらのことから、server側が8ビットごとに出力しているのに関係なくwriteがうまい感じにバイトをまとめて認識し、ascii以外のunicodeなどの対応が可能になっていた。
*/

#include <unistd.h>

int main(int ac, char **av)
{
    unsigned char c;

    c = (unsigned char)0x6c;//l
    write(1, &c, 1);

    write(1, "\n", 1);

    // 「ア」のUTF8の16進数　0xE3, 0x82, 0xA2
    c = (unsigned char)0xE3; 
    write(1, &c, 1);
    c = (unsigned char)0x82;
    write(1, &c, 1);
    c = (unsigned char)0xA2;
    write(1, &c, 1);//ア

    write(1, "\n", 1);

    // 「ア」のUTF8のバイナリ　11100011 10000010 10000010
    c = (unsigned char)0b11100011; 
    write(1, &c, 1);
    c = (unsigned char)0b10000010;
    write(1, &c, 1);
    c = (unsigned char)0b10100010;
    write(1, &c, 1);//ア

    return 0;
}
