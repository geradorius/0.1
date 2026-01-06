# VVK Studentų duomenų valdymo programa (WinForms GUI)

**Autorius:** Arnas Liudvinavičius  
**Organizacija:** VVK

## Aprašymas

Ši programa leidžia patogiai per Windows Forms sąsają:
- Įkelti duomenis iš failo
- Išsaugoti duomenis į failą
- Pasirinkti rezultatų failą
- Peržiūrėti duomenis TextBox lange
- Naudoti meniu punktus: Apie, Uždaryti, (Raktas – jei bus šifravimas)

## Paleidimas

1. Paleiskite `gui_winforms.sln` projektą Visual Studio aplinkoje.
2. Sukompiliuokite ir paleiskite programą.

## Diegimas

Diegimo vedlys sukuriamas su Inno Setup. Diegimo metu programa bus įrašyta į `C:\Program Files\VVK\Arnas_Liudvinavicius\*`.

## Pastabos
- Pradiniame variante šifravimas nenumatytas, bet meniu punktas „Raktas“ paliktas ateičiai.
- Failų pasirinkimui naudojami OpenFileDialog ir SaveFileDialog.
