int main() {
    FILE *source = fopen("source.txt", "r");
    if (source == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    Token token;
    do {
        token = getNextToken(source);
        printf("Token: Type=%d, Value=%s\n", token.type, token.value);
    } while (token.type != TOKEN_EOF);

    fclose(source);
    return 0;
}