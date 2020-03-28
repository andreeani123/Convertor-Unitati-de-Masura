# Convertor-Unitati-de-Masura

Să se realizeze un program care să permită conversia între diferite unități de măsură, plecând de la o bază de date stocată într-un fișier text, sub forma unor linii cu formatul:
n<sp>um1<sp>=<sp>m<sp>um2<lf> , unde <sp> este caracterul spațiu (cod ASCII 32), iar <lf> este caracterul LINE FEED (cod ASCII 10). Programul va încărca datele, la lansarea în execuție, 
dintr-un fișier presatablit (la alegerea programatorului) și va permite utilizatorului să-i comunice comenzile: 
C<sp>um1<sp>n=um2<cr> , unde um1 este unitatea de masură a valorii de convertit, n este valoarea de convertit, um2 este unitatea de măsură spre care se convertește, iar <cr> este caracterul Carriage Return (cod ASCII 13 – tasta Enter). Programul va răspunde cu valoarea convertită sau cu un mesaj de eroare, daca această conversie nu este posibilă.
exit<cr> – comanda de părăsire a programului
Programul trebuie să fie capabil să găsească și conversii intermediare, dacă acest lucru este necesar. De exemplu, dacă în baza de date se regăsesc liniile:
1 m = 100 cm
1 m = 1000 mm
atunci programul trebuie să fie capabil să convertească cm în mm (prin conversie intermediară în metri).

