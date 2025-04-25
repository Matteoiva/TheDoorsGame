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

