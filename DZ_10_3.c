/* В файле .txt записан полный адрес файла 
 * (возможно, без расширения).
Необходимо изменить его расширение 
на ".html" и записать результат в файл
.txt */

#include <stdio.h>
#include <string.h>

#define SIZE 10001//вместо SIZE будет подставлено 10001

void input(char *strIn) {
	FILE *in;
	in = fopen("input.txt", "r");
	while(fscanf(in, "%[^\n]", strIn) == 1);
	fclose(in);
}//читать из "input.txt", пока есть символы

void extension(char *strExt, char *buffer) {
	for(int i = strlen(strExt) - 1; i >= 0; i--) {
		//начинаем с конца массива strExt[i] и ищем '/'
		//вместо strlen(strExt) подставлена длина символьного массива
		if(strExt[i] == '/') {//если нашли '/'
			strcpy(buffer, strExt);//копируем массив в буфер
			strcat(buffer, ".html");//дописываем в конце расширение
			break;
		}
		else if(strExt[i] == '.')//иначе если нашли точку
		{
// for(int j = 0; j < i; j++)
// buffer[j] = strExt[j];
		memcpy(buffer,strExt,i);//копируем массив в буфер
		strcat(buffer, ".html");//дописываем в конце расширение
		break;
		}
	}
}

void output(char *strOut) {
	FILE *out;
	out = fopen("output.txt", "w");// открытие файла на запись
	fprintf(out, "%s", strOut);// в файл записываем strOut
	fclose(out);// закрываем файл
}//писать в файл "output.txt" из strOut

int main(int argc, char **argv) {
FILE *f;
f=fopen("input.txt", "w"); // открытие файла на запись
fprintf(f, "%s", "/DOC.TXT/qqq"); // в файл записываем строку
fclose(f); // закрываем файл
	
	
char str[SIZE], strFinal[SIZE];;
input(str);
extension(str, strFinal);
output(strFinal);
return 0;
}
