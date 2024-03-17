bool strcmp(char* a, char* b) {
    for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int strcmp(char a[], char b[]) {
    int i = 0;
    while (a[i]) {
        if (a[i] != b[i]) break;
        i++;
    }
    return a[i] - b[i];
}

bool compareChrPtr(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

void strcpy(char a[] , char b[])
{
    int i;
    for (i=0; b[i]; i++){
        a[i] = b[i];
    }
    a[i] = 0;
}