bool schermata_start(bool start, bool quit,Texture2D titolo,Vector2 titoloPosition) {
    BeginDrawing();
    DrawTextureV(titolo,titoloPosition,WHITE);

    if (start)
        DrawText("START", 180, 350, 50, BLACK);
    else
        DrawText("START", 180, 350, 50, WHITE);

    if (quit)
        DrawText("QUIT", 480, 350, 50, BLACK);
    else
        DrawText("QUIT", 480, 350, 50, WHITE);


    if (IsKeyDown(KEY_ENTER))
        return false;

    EndDrawing();
    return true;
}