#include <stdio.h>
#include <raylib.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "librerie/schermata_p.h"
#include "librerie/schermate_porte.h"
#include "librerie/controlla_suonoambientazione.h"
#include "librerie/schermata_f.h"
#include "librerie/schermata_s.h"
#include "librerie/schermata_start.h"

#define screenHeight 450
#define screenWidth 800
#define dim_fis 4

bool schermata_p(Vector2 sfondo_mortePosition,Texture2D sfondo_morte,int valori_porte[],bool enter,bool space);
bool schermata_start(bool start, bool quit,Texture2D titolo,Vector2 titoloPosition);
bool schermate_porte(Texture2D personaggio, Vector2 personaggioPosition,Texture2D porta, Vector2 portaPosition,Texture2D porta2,Vector2 porta2Position, Texture2D sfondo,Vector2 sfondoPosition,Texture2D sfondo2,Vector2 sfondo2Position,int *valori_porte,int n_stanza,Sound suonoPorta,Sound suonoMorte,Texture2D sfondo3,Vector2 sfondo3Position,Texture2D sfondo4,Vector2 sfondo4Position,Texture2D sfondo5,Vector2 sfondo5Position);
bool schermata_f();
bool schermata_s(Texture2D testo_introduzione,Vector2 testo_introduzionePosition,Sound suonoStart);
void probabilita_porte(int n_stanza,int porta, int *valore_porta,Sound suonoMorte);
void controlla_suonoambientazione( Sound suonoAmbientazione );


int main() {
    InitAudioDevice(); // Inizializza il sistema audio
    srand(time(NULL));
    SetTargetFPS(144);
    InitWindow(screenWidth, screenHeight, "DOORS");
    
    int valori_porte;                             //primi due valori per porte random, terzo per dire in quale è entrato 1 avanti; 0 morto;4 per
    int n_stanza=1;
    
    bool start = true;
    bool quit = false;
    bool spazio=false;
    bool enter=false;
    bool space=false;

    bool schermata_quitorstart = true;
    bool schermata_perso=false;
    bool schermata_storia=false;
    bool prima_schermata = false;
    bool seconda_schermata=false;
    bool terza_schermata=false;
    bool quarta_schermata=false;
    bool quinta_schermata=false;
    bool schermata_finale=false;


    // Carica l'immagine del personaggio
    Texture2D personaggio = LoadTexture("png/personaggio_html-1.png");
    Texture2D porta = LoadTexture("png/porta.png");
    Texture2D porta2 = LoadTexture("png/porta.png");
    Texture2D sfondo_morte = LoadTexture("png/morte.png");
    Texture2D testo_introduzione=LoadTexture("png/testo_presentazione.png");
    Texture2D titolo=LoadTexture("png/titolo.png");
    
    Texture2D sfondo = LoadTexture("png/sfondo/sfondo1.png");
    Texture2D sfondo2 = LoadTexture("png/sfondo/sfondo2.png");
    Texture2D sfondo3 = LoadTexture("png/sfondo/sfondo3.png");
    Texture2D sfondo4 = LoadTexture("png/sfondo/sfondo4.png");
    Texture2D sfondo5 = LoadTexture("png/sfondo/sfondo5.png");
    
    // Inizializza la posizione del personaggio
    Vector2 personaggioPosition = {screenWidth / 2-30, 420};
    Vector2 sfondo_mortePosition = {0,0};
    Vector2 testo_introduzionePosition={100,50};
    Vector2 titoloPosition={0,0};
    Vector2 portaPosition = (Vector2){325,210};
    Vector2 porta2Position = (Vector2){440,210};
    
    Vector2 sfondoPosition = {0,0};
    Vector2 sfondo2Position = {0,0};
    Vector2 sfondo3Position = {0,0};
    Vector2 sfondo4Position = {0,0};
    Vector2 sfondo5Position = {0,0};

    
    //carica file audio
    Sound suonoPorta  = LoadSound("efetto_sonoro/porta.mp3");
    Sound suonoStart = LoadSound("efetto_sonoro/start.mp3");
    Sound suonoAmbientazione = LoadSound("efetto_sonoro/ambientazione.mp3");
    Sound suonoMorte = LoadSound("efetto_sonoro/morte.mp3");

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_D))
            personaggioPosition.x += 2;
        if (IsKeyDown(KEY_A))
            personaggioPosition.x -= 2;
        if (IsKeyDown(KEY_S))
            personaggioPosition.y += 2;
        if (IsKeyDown(KEY_W))
            personaggioPosition.y -= 2;
        
        if(personaggioPosition.y+10<=300 && personaggioPosition.x<=300)
            personaggioPosition.y+=2;
        if(personaggioPosition.y+10<=300&&personaggioPosition.x>=500)
            personaggioPosition.y+=2;
        if(personaggioPosition.y+50>=screenHeight)
            personaggioPosition.y-=2;  
        if(personaggioPosition.x+50>=screenWidth)
            personaggioPosition.x-=2;
        if(personaggioPosition.x+20<=0)
            personaggioPosition.x+=2;   
        if(personaggioPosition.y<=200)
            personaggioPosition.y+=2; 
        if(personaggioPosition.x>=500&&personaggioPosition.y<=300&&personaggioPosition.y>=200)
            personaggioPosition.x-=2;
        if(personaggioPosition.x<=300&&personaggioPosition.y<=300&&personaggioPosition.y>=200)
            personaggioPosition.x+=2;
        
        // schermata start
        if (IsKeyDown(KEY_RIGHT)||(IsMouseButtonDown(MOUSE_BUTTON_LEFT)&&GetMouseX()>400)) {
            start = false;
            quit = true;
        }
        if (IsKeyDown(KEY_LEFT)||(IsMouseButtonDown(MOUSE_BUTTON_LEFT)&&GetMouseX()<400)) {
            start = true;
            quit = false;
        }

        if (schermata_quitorstart){
            schermata_quitorstart = schermata_start(start, quit, titolo, titoloPosition);
        if (schermata_quitorstart == false && start==true){
                schermata_storia = true;
        }
            else
                if(quit==true && schermata_quitorstart==false)
                    break;
        }
        
        // schermatra storia
        if (schermata_storia){
            schermata_storia = schermata_s( testo_introduzione, testo_introduzionePosition, suonoStart);
        if (schermata_storia == false){
                PlaySound(suonoAmbientazione);
                prima_schermata = true;
        }
        }
        
       //schermata perso
       if(schermata_perso){
            StopSound(suonoAmbientazione);
            enter=false;
            space=false;
            if(IsKeyDown(KEY_ENTER))
                enter=true;                
            if(IsKeyDown(KEY_SPACE))
                space=true;
           schermata_perso=schermata_p(sfondo_mortePosition,sfondo_morte,valori_porte,enter,space);
           if(schermata_perso==false && space==true){ 
                PlaySound(suonoAmbientazione);           
                prima_schermata=true;    
                personaggioPosition.x = screenWidth / 2 - 30;
                personaggioPosition.y = 400;    
           }    
           if(schermata_perso==false && enter==true)
               break;
      }
        
        //prima schermata
        if (prima_schermata) {   
            controlla_suonoambientazione(  suonoAmbientazione );
            n_stanza=1;
            prima_schermata = schermate_porte(personaggio, personaggioPosition, porta, portaPosition, porta2, porta2Position, sfondo, sfondoPosition,sfondo2,sfondo2Position, &valori_porte,n_stanza,suonoPorta,suonoMorte, sfondo3, sfondo3Position, sfondo4, sfondo4Position, sfondo5, sfondo5Position );
        if (prima_schermata == false && valori_porte == 1) {
            personaggioPosition.x = screenWidth / 2 - 30;
            personaggioPosition.y = 400;
            seconda_schermata = true;
        }
        else
            if (prima_schermata == false && valori_porte == 0)
                schermata_perso=true;
        }
        
        // seconda schermata
        if (seconda_schermata){
            controlla_suonoambientazione(  suonoAmbientazione );
            n_stanza=2;
            seconda_schermata = schermate_porte(personaggio,personaggioPosition,porta,portaPosition,porta2,porta2Position,sfondo,sfondoPosition,sfondo2,sfondo2Position,&valori_porte,n_stanza,suonoPorta ,suonoMorte, sfondo3, sfondo3Position, sfondo4, sfondo4Position, sfondo5, sfondo5Position);
        if(seconda_schermata==false && valori_porte==1){
            personaggioPosition.x=screenWidth / 2-30;
            personaggioPosition.y=400;           
            terza_schermata=true;
        }
        else
            if(seconda_schermata==false && valori_porte==0)
                schermata_perso=true;  
        }

        // terza schermata
        if (terza_schermata){
            controlla_suonoambientazione(  suonoAmbientazione );
            n_stanza=3;
            terza_schermata = schermate_porte(personaggio,personaggioPosition,porta,portaPosition,porta2,porta2Position,sfondo,sfondoPosition,sfondo2,sfondo2Position,&valori_porte,n_stanza,suonoPorta,suonoMorte , sfondo3, sfondo3Position, sfondo4, sfondo4Position, sfondo5, sfondo5Position);
        if(terza_schermata==false && valori_porte==1){
            
            personaggioPosition.x=screenWidth / 2-30;
            personaggioPosition.y=400;
            quarta_schermata=true;
        }
        else
            if(terza_schermata==false && valori_porte==0)
                schermata_perso=true;    
        }            

        // quarta schermata
        if (quarta_schermata){
            controlla_suonoambientazione(  suonoAmbientazione );          
            n_stanza=4;
            quarta_schermata = schermate_porte(personaggio,personaggioPosition,porta,portaPosition,porta2,porta2Position,sfondo,sfondoPosition,sfondo2,sfondo2Position,&valori_porte,n_stanza,suonoPorta,suonoMorte, sfondo3, sfondo3Position, sfondo4, sfondo4Position, sfondo5, sfondo5Position );
        if(quarta_schermata==false && valori_porte==1){
            personaggioPosition.x=screenWidth / 2-30;
            personaggioPosition.y=400;
            quinta_schermata=true;
        }
        else
            if(quarta_schermata==false && valori_porte==0)
                schermata_perso=true;  
        }
            
        //quinta schermata
        if (quinta_schermata){
            controlla_suonoambientazione(  suonoAmbientazione );           
            n_stanza=5;
            quinta_schermata = schermate_porte(personaggio,personaggioPosition,porta,portaPosition,porta2,porta2Position,sfondo,sfondoPosition,sfondo2,sfondo2Position,&valori_porte,n_stanza,suonoPorta,suonoMorte, sfondo3, sfondo3Position, sfondo4, sfondo4Position, sfondo5, sfondo5Position );
        if(quinta_schermata==false && valori_porte==1){
            personaggioPosition.x=screenWidth / 2-30;
            personaggioPosition.y=400;
            schermata_finale=true;
        }
        else
            if(quinta_schermata==false && valori_porte==0)
                schermata_perso=true;  
        }

        // schermata finale
        if (schermata_finale){
             StopSound(suonoAmbientazione); 
            schermata_finale = schermata_f();
            if(schermata_finale==false)
                break;
        }  
    }

    // Libera memoria alla chiusura
    UnloadTexture(personaggio);
    UnloadTexture(porta);
    UnloadTexture(porta2);
    UnloadTexture(sfondo);
    UnloadTexture(sfondo_morte);
    CloseAudioDevice();//chiude dispositivo output audio
    CloseWindow();
    return 0;
}
void probabilita_porte(int n_stanza,int porta, int *valore_porta,Sound suonoMorte){
            switch (n_stanza){
                case 1:
                    if(porta>=0&&porta<=3)
                        *valore_porta=1;
                    else{
                        *valore_porta=0;
                        PlaySound( suonoMorte);
                        }
                    break;
                case 2:
                    if(porta>=0&&porta<=3)
                        *valore_porta=1;
                    else{
                        *valore_porta=0;
                        PlaySound( suonoMorte);
                        }
                    break;
                case 3:
                    if(porta>=0&&porta<=1)
                        *valore_porta=1;
                    else{
                        *valore_porta=0;
                        PlaySound( suonoMorte);
                        }
                        
                    break;
                case 4:
                    if(porta>=0&&porta<=1)
                        *valore_porta=1;
                    else{
                        *valore_porta=0;
                        PlaySound( suonoMorte);
                        }
                    break;
                case 5:
                    if(porta==0)
                        *valore_porta=1;
                    else{
                        *valore_porta=0;
                        PlaySound( suonoMorte);
                        }
                    break;
            }     
}


