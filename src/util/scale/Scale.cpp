#include "Scale.h"

Scale *Scale::MAJOR = new Scale("Major", 7, new unsigned char[7]{0, 2, 4, 5, 7, 9, 11});
Scale *Scale::MINOR = new Scale("Minor", 7, new unsigned char[7]{0, 2, 3, 5, 7, 8, 10});
Scale *Scale::DORIAN = new Scale("Dorian", 7, new unsigned char[7]{0, 2, 3, 5, 7, 9, 10});
Scale *Scale::PHRYGIAN = new Scale("Phrygian", 7, new unsigned char[7]{0, 1, 3, 5, 7, 8, 10});
Scale *Scale::LYDIAN = new Scale("Lydian", 7, new unsigned char[7]{0, 2, 4, 6, 7, 9, 11});
Scale *Scale::MIXOLYDIAN = new Scale("Mixolydian", 7, new unsigned char[7]{0, 2, 4, 5, 7, 9, 10});
Scale *Scale::LOCRIAN = new Scale("Locrian", 7, new unsigned char[7]{0, 1, 3, 5, 6, 8, 10});
Scale *Scale::HARMONIC_MINOR = new Scale("Harmonic Minor", 7, new unsigned char[7]{0, 2, 3, 5, 7, 8, 11});
Scale *Scale::HARMONIC_MAJOR = new Scale("Harmonic Major", 7, new unsigned char[7]{0, 2, 4, 5, 7, 8, 11});
Scale *Scale::SCALES[] = {
    Scale::MAJOR,    Scale::MINOR,          Scale::DORIAN,
    Scale::PHRYGIAN, Scale::LYDIAN,         Scale::MIXOLYDIAN,
    Scale::LOCRIAN,  Scale::HARMONIC_MINOR, Scale::HARMONIC_MAJOR};

Scale::Scale(const char *name, int numNotes, unsigned char *semitones): name(name), numNotes(numNotes), semitones(semitones) {

}

const char *Scale::getName() {
  return name;
}

int Scale::getNote(unsigned char root, unsigned char index) {
  // Check if the index is negative
  if (index < 0) {
    // If it is, print an error message and return
    Serial.printf("Error: Scale semitone not found with index %d\n", index);
    return -1;
  }
  // Calculate the number of octaves by integer division of the index by the
  // number of notes
  int octaves = index / numNotes;
  // Calculate the note by adding the root, the semitone at the index modulo the
  // number of notes, and 12 times the number of octaves
  return root + semitones[index % numNotes] + 12 * octaves;
}

int *Scale::getNotesFromChord(unsigned char root, unsigned char index, ChordType *chord) {
  // Allocate an array of integers to hold the notes
  int *notes = new int[chord->numNotes];
  // Loop over the number of notes in the chord
  for (int i = 0; i < chord->numNotes; i++) {
    // For each note, calculate the note by calling getNote with the root, the
    // index plus the offset at the current index in the chord, and store it in
    // the notes array
    notes[i] = getNote(root, index + chord->offsets[i]);
  }
  // Return the notes array
  return notes;
}
