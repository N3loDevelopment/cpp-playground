#define __int32 int;
typedef unsigned int uint32;

typedef enum {
    FALSE = 0,
    TRUE = 1
} b;

b lower(char c) {
    return c >= 'a' && c <= 'z';
}

b upper(char c) {
    return c >= 'A' && c <= 'Z';
}
b is_nummeric(char c) {
    return c >= '0' && c <= '9';
}

uint32 getStringLength(const char* password) {
    uint32 len = 0;
    while (password[len] != '\0') {
        len++;
    }
    return len;
}

b not_contains_upper(const char* password) {
    for (uint32 i = 0; i < getStringLength(password); i++) {
        if (upper(password[i])) {
            return FALSE;
        }
    }
    return TRUE;
}


b not_contains_lower(const char* password) {
    for (uint32 i = 0; i < getStringLength(password); i++) {
        if (lower(password[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

b not_contains_number(const char* password) {
    for (uint32 i = 0; i < getStringLength(password); i++) {
        if (is_nummeric(password[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

b is_strong_password(const char *password) {
    if (getStringLength(password) < 8 ) return FALSE;
    if (not_contains_upper(password)) return FALSE;
    if (not_contains_lower(password)) return FALSE;
    if (not_contains_number(password)) return FALSE;
    return TRUE;

// Wollte keine extrerne Lib verwenden :D
}
