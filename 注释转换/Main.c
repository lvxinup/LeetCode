#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

enum State {
	NORMAL,	// ��ͨ
	FOUND_SLASH,	// �ҵ� '/'
	C_COMMENT,	// C ���ע��
	CPP_COMMENT,	// C++ ���ע��
	FOUND_ASTERISK	// �ҵ� *
};

void CommentConvert(FILE *pIn, FILE *pOut)
{
	enum State state = NORMAL;
	char ch, nextCh;
	while (1) {
		ch = fgetc(pIn);
		if (ch == EOF) {
			break;
		}

		switch (state)
		{
		case NORMAL:
			if (ch == '/') {
				// (1)
				state = FOUND_SLASH;
			}
			else {
				// (2)
				state = NORMAL;
				fputc(ch, pOut);
			}
			break;
		case FOUND_SLASH:
			if (ch == '*') {	// /*
				// (3)
				fprintf(pOut, "//");
				state = C_COMMENT;
			}
			else if (ch == '/'){	// //
				// (4)
				fprintf(pOut, "//");
				state = CPP_COMMENT;
			}
			else { // 5 /3
				// (5)
				fputc('/', pOut);
				fputc(ch, pOut);
				state = NORMAL;
			}
			break;
		case C_COMMENT:
			if (ch == '*') { /* xxx *             */
				state = FOUND_ASTERISK;
			}
			else {
				fputc(ch, pOut);
				if (ch == '\n') {
					fprintf(pOut, "//");
				}
				state = C_COMMENT;
			}
			break;
		case CPP_COMMENT:
			if (ch == '\n') {
				state = NORMAL;
				fputc(ch, pOut);
			}
			else {
				state = CPP_COMMENT;
				fputc(ch, pOut);
			}
			break;
		case FOUND_ASTERISK:
			if (ch == '*') {
				fputc('*', pOut);
				state = FOUND_ASTERISK;
			}
			else if (ch == '/'){
				//(8.1)
				nextCh = fgetc(pIn);
				if (nextCh != '\n') {
					fputc('\n', pOut);
				}
				ungetc(nextCh, pIn);
				state = NORMAL;
			}
			else {
				fputc('*', pOut);
				fputc(ch, pOut);
				state = C_COMMENT;
			}
			break;
		}

		const char *messages[] = {
			"��ͨ",
			"�ҵ�б����",
			"C ���ע��",
			"C++ ���ע��",
			"�ҵ��Ǻ���"
		};
		printf("��ǰ�ַ�: %c, ��ǰ״̬��: %s\n", ch, messages[state]);
		//Sleep(100);
	}
}

#include <assert.h>

int main()
{
	const char *INPUT = "input.c";
	const char *OUTPUT = "output.c";
	FILE *pIn = fopen(INPUT, "r");
	assert(pIn != NULL);
	FILE *pOut = fopen(OUTPUT, "w");
	assert(pOut != NULL);

	CommentConvert(pIn, pOut);

	fclose(pOut);	// ��򿪵��ȹ�
	fclose(pIn);

	return 0;
}