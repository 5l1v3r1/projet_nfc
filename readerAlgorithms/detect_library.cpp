#include "detect_library.h"

bool verification_all(QLabel* label_conf_libnfc, QLabel* label_conf_lecteur, QLabel* Message_utilisateur ){


    bool a = verification_libnfc(label_conf_libnfc, Message_utilisateur);
    bool b = verification_mfoc();
    bool c = verification_lecteur(label_conf_lecteur,label_conf_libnfc,Message_utilisateur);
    return a&&b&&c                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ;

}

bool verification_libnfc(QLabel* label_conf_libnfc, QLabel* Message_utilisateur){

    Message_utilisateur->setText("Detecting libNFC");
    nfc_context* context;
    nfc_init(&context);
    bool res= verification_libnfc_context(&context,label_conf_libnfc, Message_utilisateur);
    nfc_exit(context);
    return res;

}

bool verification_libnfc_context(nfc_context** context, QLabel* label_conf_libnfc, QLabel* Message_utilisateur){

    bool res= 1;

    if (*context == NULL) {
      Message_utilisateur->setText("Unable to init libnfc !");
      label_conf_libnfc->setText("Non détécté");
      label_conf_libnfc->setStyleSheet("background-color: red;");
      res=0;
    }
    else {

        Message_utilisateur->setText("libNFC detected");
    const char *acLibnfcVersion = nfc_version();
    QString message ="v.";
    message += acLibnfcVersion;
    label_conf_libnfc->setText(message);
    label_conf_libnfc->setStyleSheet("background-color: green;");
    }
    return res;
}

bool verification_mfoc(){
    return 0;
}

bool verification_lecteur(QLabel* label_conf_lecteur,QLabel* label_conf_libnfc, QLabel* Message_utilisateur ){
    nfc_context* context;
    nfc_device *pnd;
    nfc_init(&context);

    bool res= verification_libnfc_context(&context,label_conf_libnfc, Message_utilisateur);
    if (res == 0) {
      Message_utilisateur->setText("LibNFC necessaire pour detecter le lecteur !");
      label_conf_lecteur->setText("Non détécté");
      label_conf_lecteur->setStyleSheet("background-color: red;");
    }

    else {

        res=verification_lecteur_context(&context, &pnd,label_conf_lecteur,Message_utilisateur );
        if (res==1){
            nfc_close(pnd);
        }
    }

    nfc_exit(context);
    return res;
}


bool verification_lecteur_context(nfc_context**context, nfc_device **pnd, QLabel* label_conf_lecteur, QLabel* Message_utilisateur){

     Message_utilisateur->setText("Detecting reader !");
        bool res=1;
        *pnd = nfc_open(*context, NULL);

        if (*pnd == NULL) {
            Message_utilisateur->setText("Pas de lecteur détécté !");
            label_conf_lecteur->setText("Non détécté");
            label_conf_lecteur->setStyleSheet("background-color: red;");
            res =0;
        }
        // Set opened NFC device to initiator mode
        else {
          if (nfc_initiator_init(*pnd) < 0) {
              Message_utilisateur->setText("Détécté mais non utilisable!");
              label_conf_lecteur->setText("Non utilisable");
              label_conf_lecteur->setStyleSheet("background-color: orange;");
              res =0;
            }
          else {
              Message_utilisateur->setText("lecteur detecte");
              QString message ="";
              message += nfc_device_get_name(*pnd);
              label_conf_lecteur->setText(message);
              label_conf_lecteur->setStyleSheet("background-color: green;");
          }
    }

    return res;

    }
