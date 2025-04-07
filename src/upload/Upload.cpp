#include "Upload.h"

void parseSerialData(String data) {
    // Trim any whitespace
    data.trim();
    Serial.println("Received data: " + data);
    
    if (data.startsWith("CMD:")) {
      // Extract the command part after "CMD:"
      String command = data.substring(4);
      
      // Process different commands
      if (command.equals("UPDATE")) {
        // Add parsing logic
      }
    }
  }