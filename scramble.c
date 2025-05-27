#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isScramble(char* s1, char* s2) {
    // Caso base: strings vacíos o de longitud 1
    if (strlen(s1) != strlen(s2)) return false;
    if (strcmp(s1, s2) == 0) return true;
    if (strlen(s1) == 1) return *s1 == *s2;
    
    int len = strlen(s1);
    int count[26] = {0};
    
    // Verificar si tienen los mismos caracteres
    for (int i = 0; i < len; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    
    // Probar todas las posibles divisiones
    for (int i = 1; i < len; i++) {
        char left1[31], right1[31], left2[31], right2[31];
        
        // Copiar substrings para el caso sin swap
        strncpy(left1, s1, i);
        left1[i] = '\0';
        strcpy(right1, s1 + i);
        
        strncpy(left2, s2, i);
        left2[i] = '\0';
        strcpy(right2, s2 + i);
        
        if (isScramble(left1, left2) && isScramble(right1, right2))
            return true;
            
        // Caso con swap: comparar s1[0:i] con s2[len-i:len] y s1[i:len] con s2[0:len-i]
        strncpy(left2, s2, len - i);
        left2[len - i] = '\0';
        strncpy(right2, s2 + len - i, i);
        right2[i] = '\0';
        
        if (isScramble(left1, right2) && isScramble(right1, left2))
            return true;
    }
    
    return false;
}

int main() {
    char s1[31], s2[31];
    printf("Ingrese la primera cadena: ");
    scanf("%s", s1);
    printf("Ingrese la segunda cadena: ");
    scanf("%s", s2);
    
    if (isScramble(s1, s2))
        printf("true\n");
    else
        printf("false\n");
        
    return 0;
}
