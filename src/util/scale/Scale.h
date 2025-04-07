#pragma once

#include "util/ChordType.h"
#include <Arduino.h>

/**
 * @class Scale
 * @brief This class represents a musical scale.
 *
 * A scale is defined by its name, the number of notes it contains, and the
 * semitones that make up the scale. The class provides methods to get the name
 * of the scale, get a note from the scale, and get the notes from a chord in
 * the scale.
 */
class Scale {
private:
  const char *name; ///< The name of the scale
  int numNotes;     ///< The number of notes in the scale
  unsigned char *semitones;   ///< The semitones that make up the scale

public:
  static Scale *MAJOR;             ///< The Major scale
  static Scale *MINOR;             ///< The Minor scale
  static Scale *DORIAN;            ///< The Dorian scale
  static Scale *PHRYGIAN;          ///< The Phrygian scale
  static Scale *LYDIAN;            ///< The Lydian scale
  static Scale *MIXOLYDIAN;        ///< The Mixolydian scale
  static Scale *LOCRIAN;           ///< The Locrian scale
  static Scale *HARMONIC_MINOR;    ///< The Harmonic Minor scale
  static Scale *HARMONIC_MAJOR;    ///< The Harmonic Major scale
  static const int NUM_SCALES = 9; ///< The total number of scales
  static Scale *SCALES[];          ///< An array of all scales

  /**
   * @brief Construct a new Scale object
   * @param name The name of the scale
   * @param numNotes The number of notes in the scale
   * @param semitones The semitones that make up the scale
   */
  Scale(const char *name, int numNotes, unsigned char *semitones);

  /**
   * @brief Get the name of the scale
   * @return The name of the scale
   */
  const char *getName();

  /**
   * @brief Get a note from the scale
   * @param root The root note
   * @param index The index of the note
   * @return The note
   */
  int getNote(unsigned char root, unsigned char index);

  /**
   * @brief Get the notes from a chord in the scale
   * @param root The root note
   * @param index The index of the chord
   * @param chord The chord
   * @return The notes from the chord
   */
  int *getNotesFromChord(unsigned char root, unsigned char index, ChordType *chord);
};