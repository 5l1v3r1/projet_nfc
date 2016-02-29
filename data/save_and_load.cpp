#include "save_and_load.h"

/*

void remplir_donnee_from_dump(QString* text_buffer, donnee_widget** tableau_donnee){
    QString* bon= new QString;
    text_buffer->unicode();
    for(int i=0;i<1;i++){
       *bon+=text_buffer->at(i);
    }
    QString test = QString::fromUtf8("zaeae");
    tableau_donnee[0]->Donnees->setText(test);
    //tableau_donnee[0]->Donnees->setText(&bon);

}


void load_parameters(QLabel* Message_utilisateur, byte_t** keys){

    QFile fichier("params");
    QString text_buffer;

    if(fichier.open(QIODevice::ReadOnly))
     {
        int i =0;
        QTextStream flux(&fichier);
        while(!flux.atEnd())
        {
            i++;
            text_buffer = flux.readLine();
            //set_param(text_buffer,i);
        }

         fichier.close();
         Message_utilisateur->setText("Loading sucessfull");

    }

    else Message_utilisateur->setText("Erreur : Accés au fichier de paramêtre inaccessible");

}

void set_param(QString text_buffer, int i){

     * if (i==3){
        chemin_libnfc=text_buffer;
    }
    else if (i==4){
        chemin_mfoc=text_buffer;
    }

}

void afficher_donnees(QByteArray*** donnees, QVector <donnee_widget *>* donnee_wid){
    QString *string_buff= new QString;
    QString *string_buff2= new QString;

    for (int i=0; i<16; i++){

        *string_buff=QString((*donnees)[i][3].toHex().toUpper());
        for(int k=string_buff->length()-2; k>0;k=k-2){
            string_buff->insert(k,' ');
        }
        *string_buff+="\n";

        for(int j=0; j<3;j++){
            *string_buff2=QString((*donnees)[i][j].toHex().toUpper());
            for(int k=string_buff2->length()-2; k>0;k=k-2){
                string_buff2->insert(k,' ');
            }
            *string_buff2+="\n";
            *string_buff+=*string_buff2;
        }

        (*donnee_wid)[i]->Donnees->setPlainText(*string_buff);
    }

}

void afficher_Utf8(QByteArray*** donnees, QVector <donnee_widget *>* donnee_wid){
    QString *string_buff= new QString;
    QString *string_buff2= new QString;
    char c;

    for (int i=0; i<16; i++){
        *string_buff2="";
        for(int k=0; k<16;k++){
                c=(*donnees)[i][3].at(k);
                *string_buff2+=c;
        }
        *string_buff=*string_buff2;
        *string_buff+="\n";
        for(int j=0; j<3;j++){
            *string_buff2="";
            for(int k=0; k<16;k++){
                    c=(*donnees)[i][j].at(k);
                    *string_buff2+=c;
            }
            *string_buff+=*string_buff2;
            *string_buff+="\n";
            }
        (*donnee_wid)[i]->ASCII->setPlainText(*string_buff);
    }


}

void open(QByteArray*** donnees, QLabel* Message_utilisateur,QVector <donnee_widget *>*donnee_wid, QString * filename){
    QFile fichier(*filename);

    if(fichier.open(QIODevice::ReadOnly))
     {
        QByteArray arr=fichier.readAll();
        remplir_donnees(&arr,donnees);
        afficher_donnees(donnees,donnee_wid);
        afficher_Utf8(donnees,donnee_wid);
        Message_utilisateur->setText("Loading sucessfull");
            }
    else Message_utilisateur->setText("Erreur : Accés au fichier de paramêtre inaccessible");
}

void save_parameters(QLabel* Message_utilisateur, QVector <byte_t*>* keys, int nombre_clefs, int nombre_clefs_base){

    QFile fichier("params");
    QString text_buffer="******** Ce fichier à été généré automatiquement par NFC_FLO ********";
    unsigned char c;

    if(fichier.open(QIODevice::WriteOnly))
     {
        QTextStream flux(&fichier);


        flux << text_buffer << endl << endl << "!!! RAJOUTEZ VOS CLEFS MANUELLEMENT EN LES METTANT EN FIN DE FICHIER !!!";
        flux << endl << endl << endl << "*** Liste des clefs par défault ***" << endl << endl;
        for(int i=0; i<nombre_clefs_base; i++){
            for(int j=0; j<6; j++){
                c=(*keys)[i][j];
                hex_to_str(&c,&text_buffer);
                flux << text_buffer << " ";
            }
            flux << endl;
        }
        flux << endl << "*** Liste des clefs rajoutées ***" << endl << endl;
        for(int i=nombre_clefs_base; i<nombre_clefs; i++){
            for(int j=0; j<6; j++){
                c=(*keys)[i][j];
                hex_to_str(&c,&text_buffer);
                flux << text_buffer << " ";
            }
         }
        
        fichier.close();
        Message_utilisateur->setText("Saving sucessfull");
    }
    else Message_utilisateur->setText("Erreur : Accés au fichier de paramêtre inaccessible");

}

void remplir_donnees(QByteArray* arr, QByteArray*** donnees){
    for (int i=0; i<16; i++){
        for(int j=0; j<4;j++){
            (*donnees)[i][j].clear();
            for(int k=0; k<16;k++){
                    (*donnees)[i][j].push_back(arr->at(k+j*16+i*16*4));
            }
        }
    }
}


*/

