#include "mifare1k_read_write.h"
#include <QLabel>
//#include <sauvegarde.h>
typedef unsigned char byte_t;

static mifare_param mp;
nfc_device* pnd;
nfc_target_info nti;
nfc_target nt;
nfc_context* context;


bool authenticate(int block, int keynum, bool keyB, QVector <byte_t*>*  keys) {
        memcpy(mp.mpa.abtAuthUid,nti.nai.abtUid,4);
        memcpy(mp.mpa.abtKey, (*keys)[keynum], 6);

        bool res = nfc_initiator_mifare_cmd(pnd, (keyB ? MC_AUTH_B : MC_AUTH_A), block, &mp);
        if (res) {
                printf("Authentication succcessful on block %d\n",block);
        } else {
                printf("Authentication failed on block %d\n",block);
        }
        return res;
}

bool authenticate(int block, bool keyB, byte_t**  keys) {
        memcpy(mp.mpa.abtAuthUid,nti.nai.abtUid,4);
        memcpy(mp.mpa.abtKey, (*keys), 6);

        bool res = nfc_initiator_mifare_cmd(pnd, (keyB ? MC_AUTH_B : MC_AUTH_A), block, &mp);
        if (res) {
                printf("Authentication succcessful on block %d\n",block);
        } else {
                printf("Authentication failed on block %d\n",block);
        }
        return res;
}

bool readblocks(int start, int end) {
        int block;
        bool res;
        for (block=start; block<(end+1); block++) {
                res = nfc_initiator_mifare_cmd(pnd, MC_READ, block, &mp);
                if (res) {
                        printf("Block %d data: ",block);
                        //print_hex(mp.mpd.abtData,16);
                } else {
                        printf("Reading block %d failed\n",block);
                }
        }
        return res;
}



bool writeblock(int block, byte_t *data) {
        memcpy(mp.mpv.abtValue,data,16);
        bool res = nfc_initiator_mifare_cmd(pnd, MC_WRITE, block, &mp);
        if (res) {
                printf("Wrote to block %d successfully\n", block);
        } else {
                printf("Could not write to block %d\n",block);
        }
        return res;
}

bool essayer_clefs_par_defaults(int nombre_clefs, int secteur, QVector <byte_t*>* keys, bool*** clefs_connues, byte_t ****keys_determinees, bool clef_B){

    (*clefs_connues)[secteur][clef_B]=false;
    bool res=false;
    int i=0;
    while(res==false||i<nombre_clefs){
        res=authenticate(4*secteur, i, clef_B, keys);
            if(res==true){
                (*clefs_connues)[i][clef_B]=true;
                for(int j=0;j<6;j++){
                    (*keys_determinees)[secteur][clef_B][j]=(*keys)[i][j];
                }
            }
        i++;
    }
    return res;
}

bool verifier_clef_secteur(int secteur, int nombre_clefs, bool clef_B, QVector <byte_t*>* keys, bool*** clefs_connues, byte_t ****keys_determinees){

    bool res=false;
    if((*clefs_connues)[secteur][clef_B]==true){
    res=authenticate(4*secteur, clef_B, &((*keys_determinees)[secteur][0]));
    }
    if(res==false||(*clefs_connues)[secteur][clef_B]==false){
        res=essayer_clefs_par_defaults(nombre_clefs, secteur, keys, clefs_connues, keys_determinees, clef_B);
    }
    return res;

}

bool lecture_secteur(int secteur,int nombre_clefs, QVector <byte_t*>* keys, bool*** clefs_connues, byte_t ****keys_determinees){
    verifier_clef_secteur(secteur,nombre_clefs,false,keys,clefs_connues,keys_determinees);
    verifier_clef_secteur(secteur,nombre_clefs,true,keys,clefs_connues,keys_determinees);

    bool res=false;
    if ((*clefs_connues)[secteur][0]){
        res=authenticate(4*secteur, false, &((*keys_determinees)[secteur][0]));
        if(res=true){
            //res=readblock
        }
    }
    else if ((*clefs_connues)[secteur][1]){
        res=authenticate(4*secteur, true, &((*keys_determinees)[secteur][1]));
        if(res=true){
            //res=readblock
        }
    }
}




void main_lecture(){

}

bool init_all(){

    bool res=1;

    nfc_init(&context);
    if (context == NULL) {
        res=0;
    }
    else {
        pnd = nfc_open(context, NULL);
        if(pnd==NULL){
            res=0;
            nfc_exit(context);
        }
        else {
            if (nfc_initiator_init(pnd) < 0) {
                res=0;
                nfc_close(pnd);
                nfc_exit(context);
            }
        }
    }
    return res;
}


void exit_all(){
    nfc_close(pnd);
    nfc_exit(context);

}

bool trouver_tag(QLabel* ID_Tag_read, QLabel* Message_utilisateur){

    Message_utilisateur->setText("Searching for a tag !");
    QString *s = new QString;
    QString message = "";

        nfc_modulation nmMifare;
        nmMifare.nmt = NMT_ISO14443A;
        nmMifare.nbr = NBR_106;

    bool res=init_all();
    if(res==1){
        ID_Tag_read->setText("Waiting for a tag");

          if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0) {
              Message_utilisateur->setText("Tag found");
            printf("The following (NFC) ISO14443A tag was found:\n");
            printf("    ATQA (SENS_RES): ");
            //print_hex(nt.nti.nai.abtAtqa, 2);
            printf("       UID (NFCID%c): ", (nt.nti.nai.abtUid[0] == 0x08 ? '3' : '1'));

            for(int i=0; i<nt.nti.nai.szUidLen;i++){
                //hex_to_str(&((nt.nti.nai.abtUid)[i]),s);
                message +=  *s;
                message += " ";
            }
            ID_Tag_read->setText(message);
            //print_hex(nt.nti.nai.abtUid, nt.nti.nai.szUidLen);

            printf("      SAK (SEL_RES): ");
            //print_hex(&nt.nti.nai.btSak, 1);
            if (nt.nti.nai.szAtsLen) {
              printf("          ATS (ATR): ");
              //print_hex(nt.nti.nai.abtAts, nt.nti.nai.szAtsLen);
            }
          }
          else {
              Message_utilisateur->setText("No tag found");
          }

    }
    else {
        Message_utilisateur->setText("Init failed");
    }
    exit_all();
    //Message_utilisateur->setText(" !");
}
