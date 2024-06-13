// NOTES
#define BUZZER 2
#define NOTE_SILENCE 0
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_G6  1568

void introMusic() {
  int melody[] = {
    NOTE_G5, NOTE_A5, NOTE_D6, NOTE_G6
  };

  int noteDurations[] = {
    8, 8, 8, 4
  };

  int melodyLength = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    int noteDuration = 1500 / noteDurations[thisNote];
    
    if (melody[thisNote] != NOTE_SILENCE) {
        tone(BUZZER, melody[thisNote], noteDuration);
    }
    delay(noteDuration);

    noTone(BUZZER);

    int pauseBetweenNotes = noteDuration * 0.30;
    delay(pauseBetweenNotes);
  }
}

void funeralMarch() {
  int funeralMelody[] = {
    NOTE_A5, NOTE_A5, NOTE_A5, NOTE_F5, 
    NOTE_C6, NOTE_A5, NOTE_F5, NOTE_C6, NOTE_A5,
  };

  int funeralNoteDurations[] = {
    4, 4, 4, 4, 
    12, 4, 4, 12, 4
  };

  int melodyLength = sizeof(funeralMelody) / sizeof(int);
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    int noteDuration = 2000 / funeralNoteDurations[thisNote];
    
    if (funeralMelody[thisNote] != NOTE_SILENCE) {
        tone(BUZZER, funeralMelody[thisNote], noteDuration);
    }
    delay(noteDuration);

    noTone(BUZZER);

    int pauseBetweenNotes = noteDuration * 0.30;
    delay(pauseBetweenNotes);
  }
}

void finalFantasy() {
  int melody[] = {
    NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_B5,
    NOTE_CS6, NOTE_DS6, NOTE_SILENCE, NOTE_CS6, NOTE_DS6
  };

  // Duraciones de las notas: 4 = negra, 8 = corchea, etc.
  int noteDurations[] = {
    16, 16, 16, 4, 4, 
    4, 16, 8, 8, 1
  };
  
  int melodyLength = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {

    int noteDuration = 1500 / noteDurations[thisNote];
    // Si la nota no es un silencio, toca la nota
    if (melody[thisNote] != NOTE_SILENCE) {
      tone(BUZZER, melody[thisNote], noteDuration);
    }
    
    // Espera la duración de la nota
    delay(noteDuration);

    // Detiene el tono después de la duración de la nota
    noTone(BUZZER);

    // Pausa entre notas para mejorar la separación
    int pauseBetweenNotes = noteDuration * 0.30;
    delay(pauseBetweenNotes);
  }
}