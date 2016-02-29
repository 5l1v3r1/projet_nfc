#ifndef CONVERTION
#define CONVERTION

#include <QString>

void str_char_to_str_hex(QString* s_char, QString* s_hex);
void str_char_to_str_hex_2(QString* s_char, QString* s_hex);

void uchar_hex_to_str( unsigned char* c, QString *s);
void char_hex_to_str(char* c, QString *s);

void str_to_uchar_hex(QString* s, unsigned char *c);



#endif // CONVERTION

