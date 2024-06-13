// NOTES
#define BUZZER 2
#define NOTE_SILENCE 0
#define NOTE_A6 1760
#define NOTE_F6 1397
#define NOTE_C7 2093
#define NOTE_DS5 622
#define NOTE_B4 494
#define NOTE_CS5 554
void funeralMarch()
{
  int funeralMelody[] = {
      NOTE_A6, NOTE_A6, NOTE_A6, NOTE_F6, NOTE_A6, NOTE_A6, NOTE_F6, NOTE_A6,
      NOTE_A6, NOTE_F6, NOTE_C7, NOTE_A6, NOTE_F6, NOTE_C7, NOTE_A6};
  int funeralNoteDurations[] = {
      4, 8, 4, 4, 8, 4, 4, 8,
      4, 4, 4, 4, 8, 4, 4};
  int melodyLength = sizeof(funeralMelody) / sizeof(int);
  for (int thisNote = 0; thisNote < melodyLength; thisNote++)
  {
    int noteDuration = 1000 / funeralNoteDurations[thisNote];
    tone(BUZZER, funeralMelody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER);
  }
}
void finalFantasy()
{
  int melody[] = {
      NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_B4,
      NOTE_CS5, NOTE_DS5, NOTE_SILENCE, NOTE_CS5, NOTE_DS5};
  // Duraciones de las notas: 4 = negra, 8 = corchea, etc.
  int noteDurations[] = {
      16, 16, 4, 4, 8,
      4, 16, 8, 8, 1};
  for (int thisNote = 0; thisNote < 10; thisNote++)
  {
    int noteDuration = 1500 / noteDurations[thisNote];
    // Si la nota no es un silencio, toca la nota
    if (melody[thisNote] != NOTE_SILENCE)
    {
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