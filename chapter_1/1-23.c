/**
 * @description Write a program to remove all comments from a C program. Don't forget to handle quoted strings
and character constants properly. C comments don't nest.
 */

#include <stdio.h>
#include "../lib.h"

#define lex_t int
#define token_t int
#define MAX_INPUT_SIZE 8086
#define LEX_LINE_COMMENT 0
#define LEX_BLOCK_COMMENT_L 1
#define LEX_BLOCK_COMMENT_R 2
#define LEX_NEWLINE 3
#define LEX_QUOTE 4
#define LEX_OTHER 5
#define TOKEN_LINE_COMMENT 0
#define TOKEN_BLOCK_COMMENT 1
#define TOKEN_QUOTE 2
#define TOKEN_OTHER 3 // TODO can use enum!

void read_input(char buffer[]);
void remove_comments(char input[], char output[]);
void push_char_to_lex(char c, char lex[]);
lex_t get_lex_type(char s[]);

int main()
{
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];

    read_input(input);
    remove_comments(input, output);

    printf("%s", output);
}

void read_input(char buffer[])
{
    int i = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

void remove_comments(char input[], char output[])
{
    char lex[3] = {'\0', '\0', '\0'};
    token_t token_type = TOKEN_OTHER;

    int i = 0;
    int j = 0;
    char c;
    while ((c = input[i++]) != '\0')
    {
        push_char_to_lex(c, lex);

        switch (get_lex_type(lex))
        {
        case LEX_LINE_COMMENT:
            if (token_type != TOKEN_QUOTE)
            {
                token_type = TOKEN_LINE_COMMENT;
                j--;
            }
            break;
        case LEX_BLOCK_COMMENT_L:
            if (token_type != TOKEN_QUOTE)
            {
                token_type = TOKEN_BLOCK_COMMENT;
                j--;
            }
            break;
        case LEX_BLOCK_COMMENT_R:
            if (token_type != TOKEN_QUOTE)
            {
                token_type = TOKEN_OTHER;
            }
        case LEX_NEWLINE:
            if (token_type == TOKEN_LINE_COMMENT)
            {
                token_type = LEX_OTHER;
                if (j > 0 && output[j - 1] != '\n')
                {
                    output[j++] = c;
                }
            }
            else if (token_type != TOKEN_BLOCK_COMMENT)
            {
                output[j++] = c;
            }
            break;
        case LEX_QUOTE:
            token_type = (token_type == TOKEN_QUOTE) ? TOKEN_OTHER : TOKEN_QUOTE;
        case LEX_OTHER:
        default:
            if (token_type != TOKEN_LINE_COMMENT && token_type != TOKEN_BLOCK_COMMENT)
            {
                output[j++] = c;
            }
            break;
        }
    }
    output[j] = '\0';
}

void push_char_to_lex(char c, char lex[])
{
    if (lex[1] != '\0')
    {
        lex[0] = lex[1];
    }
    lex[lex[0] != '\0'] = c;
}

lex_t get_lex_type(char lex[])
{
    if (str_equals(lex, "//"))
    {
        return LEX_LINE_COMMENT;
    }
    else if (str_equals(lex, "/*"))
    {
        return LEX_BLOCK_COMMENT_L;
    }
    else if (str_equals(lex, "*/"))
    {
        return LEX_BLOCK_COMMENT_R;
    }
    else if (lex[0] != '\\' && lex[1] == '"') // TODO inside single quotes?
    {
        return LEX_QUOTE;
    }
    else if (lex[0] == '\n' || lex[1] == '\n')
    {
        return LEX_NEWLINE;
    }
    else
    {
        return LEX_OTHER;
    }
}
