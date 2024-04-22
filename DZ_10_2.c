/* В файле .txt записаны символы. 
 * В файле .txt необходимо удалить все 
 * лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи 
разработать функцию. Результат
записать в .txt */

#include <stdio.h>
enum States { Start, In, Out };

void change_symbols();

int main() {
	
FILE *f;
f=fopen("input.txt", "w"); // открытие файла на запись
fprintf(f, "%s", " Hello  world!"); // в файл записываем строку
fclose(f); // закрываем файл

void change_symbols();

return 0;
}


void change_symbols() { 
FILE *f_in = fopen("input.txt", "r");
FILE *f_out = fopen("output.txt", "w");
int c, state = Start;

while ((c = fgetc(f_in)) != EOF) {
	switch (state) {
		case Start:
		if (c != ' ') 	{
			state = In;
			fputc(c, f_out);
		}
		break;
		case In:
			if (c == ' ')
				state = Out;
			else
				fputc(c, f_out);
			break;
		case Out:
			if (c != ' ') {
				state = In;
			fputc(' ', f_out);
			fputc(c, f_out);
		}
		break;
	}
fclose(f_in);
fclose(f_out);
}
}
