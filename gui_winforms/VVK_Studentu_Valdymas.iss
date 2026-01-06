; Inno Setup Script
#define MyAppName "VVK Studentų duomenų valdymas"
#define MyAppVersion "1.0"
#define MyAppPublisher "Arnas Liudvinavičius"
#define MyAppURL "https://github.com/ArnasLiudvinavicius"
#define MyAppExeName "gui_winforms.exe"

[Setup]
AppId={{A1B2C3D4-E5F6-47A8-9B0C-1234567890AB}}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
DefaultDirName={autopf}\VVK\Arnas_Liudvinavicius
DefaultGroupName={#MyAppName}
OutputDir=.
OutputBaseFilename=VVK_Studentu_Valdymas_Setup
Compression=lzma
SolidCompression=yes

[Files]
Source: "Release\gui_winforms.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\VVK Studentų duomenų valdymas"; Filename: "{app}\gui_winforms.exe"
Name: "{group}\Pašalinti VVK Studentų duomenų valdymą"; Filename: "{uninstallexe}"

[Run]
Filename: "{app}\gui_winforms.exe"; Description: "Paleisti programą"; Flags: nowait postinstall skipifsilent
