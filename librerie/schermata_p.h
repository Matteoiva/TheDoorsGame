bool schermata_p(Vector2 sfondo_mortePosition,Texture2D sfondo_morte,int valori_porte[],bool enter,bool space){
    BeginDrawing();
        DrawTextureV(sfondo_morte, sfondo_mortePosition, WHITE);
        DrawText("Press enter to quit",560,400,20,WHITE);
        DrawText("Press space to restart game",460,420,20,WHITE);
        if(enter==true)
            return false;
        if(space==true)
            return false;
    EndDrawing();
    return true;
}