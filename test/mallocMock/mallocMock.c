#include <mallocMock.h>
#include <loadSymbols.h>
#include <stdlib.h>

static unsigned int numberOfSucessMalloc=0;
static void* (*internalMalloc)(size_t)=NULL;

unsigned int initMalloc(unsigned int numberOfMalloc)
{
  unsigned int resp=1;
  numberOfSucessMalloc=numberOfMalloc;

  if(NULL == internalMalloc)
  {
    internalMalloc=loadSymbol("malloc");
    if(NULL == internalMalloc)
    {
      resp=0;
    }
  }
  return resp;
}

void finishMalloc()
{
  if(NULL != internalMalloc)
  {
    unloadSymbol(internalMalloc);
  }
}

void* malloc(size_t size)
{
  void* resp=NULL;
  if(0 < numberOfSucessMalloc)
  {
    numberOfSucessMalloc--;
    resp=internalMalloc(size);
  }
  return resp;
}
