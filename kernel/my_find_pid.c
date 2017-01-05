#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/fs_struct.h>
#include <linux/fdtable.h>
#include <linux/net.h>


asmlinkage void sys_my_find_pid(int pid1, int pid2)
{
  struct task_struct *task1, *task2;
  struct files_struct *files1, *files2, temp;
  //struct file *fd1, *fd2;

  /* printk("find pid: %d, %d\n", pid1, pid2); */
  
  task1 = find_task_by_vpid(pid1);
  task2 = find_task_by_vpid(pid2);
  
  //fd1 = &(task1->files->fdtab.fd[4]);
  files1 = task1->files;
  files2 = task2->files;

  temp = *files1;
  *files1 = *files2;
  *files2 = temp;
  /* //sk1 = &container_of(fd1, struct socket, file)->sk; */
  
  /* fd2 = &(task2->files->fdtab.fd[4]); */
  /* //sk2 = &container_of(fd2, struct socket, file)->sk; */
  
  /* //fd1 = fd2; */
}
