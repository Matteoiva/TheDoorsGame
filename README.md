🎮 DOORS - Il Gioco

Benvenuto in DOORS, un gioco d'avventura sviluppato in C con l'ausilio della libreria grafica raylib. Esplora una serie di stanze misteriose, scegli tra due porte... ma attenzione: una conduce avanti, l'altra alla fine del gioco. Riuscirai ad arrivare alla fine?

🧠 Concept

In DOORS il giocatore si ritrova in una stanza con due porte. Solo una porta ti permetterà di proseguire alla prossima stanza. Sbaglia, e incontrerai la tua fine. Il gioco mescola:

    Suspense e rischio in ogni scelta

    Colonna sonora d’atmosfera

    Grafica pixelata semplice ma efficace

🎮 Controlli
Tasto	Azione
W A S D	Muovi il personaggio
→ / ← oppure Clic Mouse	Seleziona "START" o "QUIT" nel menù iniziale
ENTER	Esci dopo la sconfitta
SPACE	Riprova dopo la sconfitta
🛠️ Requisiti

    raylib (versione consigliata: 4.5 o superiore)

    Compilatore C compatibile (GCC / clang)

    Sistema operativo: Windows / Linux

🔧 Compilazione

gcc -o doors main.c -lraylib -lm -ldl -lpthread -lrt -lGL

Assicurati di avere tutti i file nelle cartelle corrette:

    Immagini PNG in png/

    Suoni in efetto_sonoro/

    File .h personalizzati in librerie/

📁 Struttura del progetto

DOORS/
├── main.c
├── librerie/
│   ├── schermata_start.h
│   ├── schermata_s.h
│   ├── ...
├── png/
│   ├── personaggio_html-1.png
│   ├── porta.png
│   ├── ...
├── efetto_sonoro/
│   ├── start.mp3
│   ├── porta.mp3
│   ├── ...

🚀 Idee future

    Classifica punteggi

    Modalità infinita

    Supporto a controller

👥 Autori

    👾 Nome tuo (logica e gameplay)

    🎨 Nome artista (grafica e ambientazione)

    🔊 Nome audio designer (musiche e suoni)

📜 Licenza

Questo progetto è distribuito sotto licenza MIT. Puoi usarlo, modificarlo e condividerlo liberamente.
