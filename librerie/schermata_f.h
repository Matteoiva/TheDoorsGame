bool schermata_f(){
    BeginDrawing();
        ClearBackground(GRAY);
        DrawText("COMPLIMETNI !!", 200, 100,50,YELLOW);
        DrawText("SEI RIUSCITO A COMPLETARE IL GIOCO", 50, 200,30,YELLOW);
        DrawText("Press enter to quit",580,425,20,WHITE);
    EndDrawing();
    if(IsKeyDown(KEY_ENTER))
        return false;
    return true;
    
}