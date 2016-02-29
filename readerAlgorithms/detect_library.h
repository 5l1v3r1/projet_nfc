#ifndef DETECTION_BIBLI_H
#define DETECTION_BIBLI_H

#include "library_include.h"
#include <QLabel>

bool verification_mfoc();

bool verification_all(QLabel* label_conf_libnfc, QLabel* label_conf_lecteur, QLabel* Message_utilisateur );

bool verification_libnfc(QLabel* label_conf_libnfc, QLabel* Message_utilisateur);

bool verification_libnfc_context(nfc_context** context, QLabel* label_conf_libnfc, QLabel* Message_utilisateur);

bool verification_lecteur(QLabel* label_conf_lecteur,QLabel* label_conf_libnfc, QLabel* Message_utilisateur );


bool verification_lecteur_context(nfc_context** context, nfc_device **pnd, QLabel* label_conf_lecteur, QLabel* Message_utilisateur);


#endif // DETECTION_BIBLI_H
