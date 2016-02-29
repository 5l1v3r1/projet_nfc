#include "convertion.h"

void str_char_to_str_hex(QString* s_char, QString* s_hex){

    QByteArray arr;
    arr=s_char->toLatin1();
    QString* s= new QString(arr.toHex());
    *s_hex=*s;

/*
    char* cara = arr.toHex().data();
    QString* str_buffer= new QString;
    unsigned char cara_unsigned;

    *s_hex="";

    for(int i=0; i<arr.length(); i++){
        cara_unsigned= (unsigned char) cara[i];
        hex_to_str(&cara_unsigned,str_buffer);
        *s_hex+=*str_buffer;
        *s_hex+=" ";
    }
    */
}

void str_char_to_str_hex_2(QString* s_char, QString* s_hex){
    QChar* arr = s_char->data();
    QString* str_buffer= new QString;
    unsigned char cara;
    *s_hex="";

    for(int i=0; i<s_char->length(); i++){
        cara=arr[i].cell();
        uchar_hex_to_str(&cara,str_buffer);
        *s_hex+=*str_buffer;
        *s_hex+=" ";
        cara=arr[i].row();
        uchar_hex_to_str(&cara,str_buffer);
        *s_hex+=*str_buffer;
        *s_hex+=" ";
    }
}


void uchar_hex_to_str(unsigned char* c, QString *s){
    int count;
    unsigned char number =  *c;



    if(number>=240) {
        *s='F';
        count=240;
    }
    else if(number>=224){
        *s='E';
        count=224;
    }
    else if(number>=208){
        *s='D';
        count=208;
    }
    else if(number>=192){
        *s='C';
        count=192;
    }
    else if(number>=176){
        *s='B';
        count=176;
    }
    else if(number>=160){
        *s='A';
        count=160;
    }
    else if(number>=144){
        *s='9';
        count=144;
    }
    else if(number>=128){
        *s='8';
        count=128;
    }
    else if(number>=112){
        *s='7';
        count=112;
    }
    else if(number>=96){
        *s='6';
        count=96;
    }
    else if(number>=80){
        *s='5';
        count=80;
    }
    else if(number>=64){
        *s='4';
        count=64;
    }
    else if(number>=48){
        *s='3';
        count=48;
    }
    else if(number>=32){
        *s='2';
        count=32;
    }
    else if(number>=16){
        *s='1';
        count=16;
    }
    else{
        *s='0';
        count=0;
    }

    number -=count;

    if(number==15) {
        *s+='F';
    }
    else if(number==14){
        *s+='E';
    }
    else if(number==13){
        *s+='D';
    }
    else if(number==12){
        *s+='C';
    }
    else if(number==11){
        *s+='B';
    }
    else if(number==10){
        *s+='A';
    }
    else if(number==9){
        *s+='9';
    }
    else if(number==8){
        *s+='8';
    }
    else if(number==7){
        *s+='7';
    }
    else if(number==6){
        *s+='6';
    }
    else if(number==5){
        *s+='5';
    }
    else if(number==4){
        *s+='4';
    }
    else if(number==3){
        *s+='3';
    }
    else if(number==2){
        *s+='2';
    }
    else if(number==1){
        *s+='1';
    }
    else{
        *s+='0';
    }
}

void str_to_uchar_hex(QString* s,unsigned char *c){
    unsigned char count=0;
    if(s->at(0)=='F') {
        count=240;
    }
    else if(s->at(0)=='E') {
        count=224;
    }
    else if(s->at(0)=='D') {
        count=208;
    }
    else if(s->at(0)=='C') {
        count=192;
    }
    else if(s->at(0)=='B') {
        count=176;
    }
    else if(s->at(0)=='A') {
        count=160;
    }
    else if(s->at(0)=='9') {
        count=144;
    }
    else if(s->at(0)=='8') {
        count=128;
    }
    else if(s->at(0)=='7') {
        count=112;
    }
    else if(s->at(0)=='6') {
        count=96;
    }
    else if(s->at(0)=='5') {
        count=80;
    }
    else if(s->at(0)=='4') {
        count=64;
    }
    else if(s->at(0)=='3') {
        count=48;
    }
    else if(s->at(0)=='2') {
        count=32;
    }
    else if(s->at(0)=='1') {
        count=16;
    }
    else if(s->at(0)=='0') {
        count=0;
    }
    else{
        count=0;
    }

    if(s->at(1)=='F') {
        count+=15;
    }
    else if(s->at(0)=='E') {
        count+=14;
    }
    else if(s->at(0)=='D') {
        count+=13;
    }
    else if(s->at(0)=='C') {
        count+=12;
    }
    else if(s->at(0)=='B') {
        count+=11;
    }
    else if(s->at(0)=='A') {
        count+=10;
    }
    else if(s->at(0)=='9') {
        count+=9;
    }
    else if(s->at(0)=='8') {
        count+=8;
    }
    else if(s->at(0)=='7') {
        count+=7;
    }
    else if(s->at(0)=='6') {
        count+=6;
    }
    else if(s->at(0)=='5') {
        count+=5;
    }
    else if(s->at(0)=='4') {
        count+=4;
    }
    else if(s->at(0)=='3') {
        count+=3;
    }
    else if(s->at(0)=='2') {
        count+=2;
    }
    else if(s->at(0)=='1') {
        count+=1;
    }
    else if(s->at(0)=='0') {
        count+=0;
    }
    else{
        count+=0;
    }
    *c= count;

}
