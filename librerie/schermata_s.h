bool schermata_s(Texture2D testo_introduzione,Vector2 testo_introduzionePosition,Sound suonoStart){
    BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureV(testo_introduzione,testo_introduzionePosition,WHITE);
        DrawText("Press enter ->",640,425,20,GRAY);    
        DrawText("Press space to enter into the doors",20,425,20,GRAY); 
    EndDrawing();
    if(IsKeyPressed(KEY_ENTER)){
        PlaySound(suonoStart );         
        return false;
    }
    return true;
}