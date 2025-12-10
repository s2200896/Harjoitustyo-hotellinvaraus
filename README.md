# Harjoitustyo-hotellinvaraus
**Sisu Salakoski**  
*toivottavasti 5p*

## Toiminta

- Ohjelman päätoiminnot ovat:  
  **Huoneen varaus**, **Tulosta viimeisin varaus**, **Etsi varaus**,  
  **Peruuta varaus**, **Peruuta kaikki varaukset**, **Tulosta kaikki varaukset**.
- Ohjelma täyttää *4p vaatimukset*.  
  Vaatimusten lisäksi ohjelman sulkeutuessa olemassa olevat varaukset ja huonetilanteet kirjoitetaan tiedostoon ja ohjelman käynnistyessä ne luetaan tiedostosta vektoreihin.  
  Jos varauksia ei ole, huoneiden määrä generoidaan uudelleen.
  Kaikista käyttäjän syötteistä tarkistetaan, että ne ovat oikeaa tyyppiä ja ovat mahdollisten rajauksien sisäpuolella.
- **Lisätoiminnallisuus:**  
  - Mahdollisuus peruuttaa kaikki varaukset kerralla.  
  - Huonetta varatessa, kun kaikki tiedot on syötetty, tulostetaan käyttäjän syöttämät tiedot ja kysytään ovatko tiedot oikeat.  
    Jos tiedot ovat virheelliset, käyttäjä voi valita seuraavista:  
    *Vaihda nimi*, *Vaihda huone*, *Muuta öiden määrää*, *Aloita alusta*, *Peruuta varaus*, *Jatka*.

---

## Lyhyt kuvaus toiminnoista

### 1. Huoneen varaus
Käyttäjältä kysytään:
- Minkä tyyppisen huoneen hän haluaa varata.  
- Haluaako hän valita huoneen itse vai valitaanko se automaattisesti.  
- Kuinka monelle yölle varaus tehdään.  
- Asiakkaan nimi ja nimen vahvistus.

Tämän jälkeen tulostetaan varauksen tiedot ja kysytään ovatko ne oikein.  
Jos eivät ole, annetaan vaihtoehtoja tietojen muuttamiseen.

Kun tiedot on vahvistettu, tulostetaan varauksen alennus ja lasku, ja kysytään vahvistetaanko varaus.  
Jos ei, annetaan samat muokkausvaihtoehdot kuin aiemmin.

---

### 2. Tulosta viimeisin varaus
Tulostetaan viimeisimmän varauksen tiedot:
- Varausnumero  
- Huonenumero  
- Huonetyyppi  
- Asiakkaan nimi  
- Öiden määrä  
- Alennusprosentti  
- Lasku  

---

### 3. Etsi varaus
Kysytään haetaanko varausta **nimellä** vai **varausnumerolla**.  
Jos varaus löytyy, tulostetaan samat tiedot kuin kohdassa ”Tulosta viimeisin varaus”.  
Jos varausta ei löydy, kerrotaan tästä ja kysytään, halutaanko yrittää uudelleen.

---

### 4. Peruuta varaus
Käyttäjältä kysytään varausnumero, jonka avulla varaus etsitään.  
- Jos varaus löytyy, tulostetaan tiedot ja kysytään halutaanko se poistaa.  
- Jos ei löydy, ilmoitetaan tästä ja kysytään halutaanko yrittää toisella varausnumerolla.

---

### 5. Peruuta kaikki varaukset
- Jos varauksia ei ole, tulostetaan tästä kertova viesti.  
- Muussa tapauksessa kysytään varmistus kaikkien varausten poistamiselle.  
  Jos käyttäjä vahvistaa, kaikki varaukset poistetaan.

---

### 6. Tulosta kaikki varaukset
Sama toiminnallisuus kuin kohdassa *Tulosta viimeisin varaus*, mutta tulostetaan **kaikkien** olemassa olevien varausten tiedot numeroituna.

---
