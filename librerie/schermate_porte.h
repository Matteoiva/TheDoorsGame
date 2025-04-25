bool schermate_porte(Texture2D personaggio, Vector2 personaggioPosition,Texture2D porta, Vector2 portaPosition,Texture2D porta2,Vector2 porta2Position, Texture2D sfondo,Vector2 sfondoPosition,Texture2D sfondo2,Vector2 sfondo2Position,int *valori_porte,int n_stanza,Sound suonoPorta,Sound suonoMorte,Texture2D sfondo3,Vector2 sfondo3Position,Texture2D sfondo4,Vector2 sfondo4Position,Texture2D sfondo5,Vector2 sfondo5Position) {
    
    int porta_2=rand()%(7-n_stanza); //da 0 - 4
    int porta_1=rand()%(7-n_stanza);
    int val_porta=0;
  
    BeginDrawing();
    switch (n_stanza){
        case 1:
            DrawTextureV(sfondo, sfondoPosition, WHITE);
            portaPosition = (Vector2){325,210};
            porta2Position = (Vector2){440,210};
            break;
        case 2:
            DrawTextureV(sfondo2, sfondo2Position, WHITE);
            portaPosition = (Vector2){300, 200};
            porta2Position = (Vector2){400, 200};
            break;
        case 3:
            DrawTextureV(sfondo3, sfondo3Position, WHITE);
            portaPosition = (Vector2){270, 270};
            porta2Position = (Vector2){390, 270};
            break;
        case 4:
            DrawTextureV(sfondo4, sfondo4Position, WHITE);
            portaPosition = (Vector2){330, 240};
            porta2Position = (Vector2){490, 190};
            break;    
        case 5:
            DrawTextureV(sfondo5, sfondo5Position, WHITE);
            portaPosition=(Vector2){280, 250};
            porta2Position = (Vector2){400, 250};
            break;   
    }
    
    DrawTextureV(porta, portaPosition, WHITE);
    DrawTextureV(porta2, porta2Position, WHITE);
    DrawTextureV(personaggio, personaggioPosition, WHITE);
    DrawText(TextFormat("Stanza %d",n_stanza),50,20,30,WHITE);
    
    EndDrawing();
      
     if (IsKeyReleased(KEY_SPACE)&&CheckCollisionPointRec(personaggioPosition, (Rectangle){ portaPosition.x, portaPosition.y, 110, 110 })){
            PlaySound(suonoPorta); 
            probabilita_porte( n_stanza, porta_1, &val_porta,suonoMorte);
            *valori_porte=val_porta;
        
           return false;
    }    
    if (IsKeyReleased(KEY_SPACE)&&CheckCollisionPointRec(personaggioPosition, (Rectangle){ porta2Position.x, porta2Position.y, 110, 110 })){
            PlaySound(suonoPorta );
             probabilita_porte( n_stanza, porta_2, &val_porta, suonoMorte);
            *valori_porte=val_porta;
            return false;
    }
    
    return true;
}