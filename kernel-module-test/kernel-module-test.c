#include <linux/init.h>	/* Needed for the macros */
#include <linux/module.h> /* Needed by all modules */ 
#include <linux/printk.h> /* Needed for pr_info() */ 
 
int module_test_init(void) 
{ 
    pr_info("Hello world from %s.\n", THIS_MODULE->name); 
 
    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 
 
void module_test_exit(void) 
{ 
    pr_info("Goodbye world from %s.\n", THIS_MODULE->name); 
} 
 
module_init(module_test_init);
module_exit(module_test_exit);

MODULE_LICENSE("GPL");
