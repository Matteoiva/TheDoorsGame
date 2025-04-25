void  controlla_suonoambientazione( Sound suonoAmbientazione ){
    if(IsSoundPlaying(suonoAmbientazione)==false)
        PlaySound(suonoAmbientazione);
}