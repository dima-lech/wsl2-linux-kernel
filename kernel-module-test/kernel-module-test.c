#include <linux/module.h> /* Needed by all modules */ 
#include <linux/printk.h> /* Needed for pr_info() */ 
 
int init_module(void) 
{ 
    pr_info("Hello world from %s.\n", THIS_MODULE->name); 
 
    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 
 
void cleanup_module(void) 
{ 
    pr_info("Goodbye world from %s.\n", THIS_MODULE->name); 
} 
 
MODULE_LICENSE("GPL");