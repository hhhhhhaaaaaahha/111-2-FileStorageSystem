/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"

#include "synchconsole.h"

OpenFileId SysOpen(char *name)
{
  return kernel->fileSystem->OpenAFile(name);
}

int SysWrite(char *buffer, int size, OpenFileId id)
{
  return kernel->fileSystem->WriteFile0(buffer, size, id);
}

int SysRead(char *buffer, int size, OpenFileId id)
{
  return kernel->fileSystem->ReadFile(buffer, size, id);
}

int SysClose(OpenFileId id)
{
  return kernel->fileSystem->CloseFile(id);
}

void SysHalt()
{
  kernel->interrupt->Halt();
}

void SysPrintInt(int number)
{
  kernel->synchConsoleOut->PutInt(number);
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
  // return value
  // 1: success
  // 0: failed
  return kernel->interrupt->CreateFile(filename);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
