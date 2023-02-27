
import socket
import asyncio
import os

from dataclasses import dataclass


@dataclass
class Client:

    _procs = []


    async def proc_start(self, cmd,  args=[]):
        tst = asyncio.subprocess.PIPE
        proc = await asyncio.create_subprocess_exec( cmd, *args)
        self._procs.append(proc)
        return proc

# ----------------------------------------
    async def _proc_kill(self, proc):
        proc.kill()
        await proc.wait()
        # proc._transport.close()

# ----------------------------------------
    async def procs_kill(self):
       for proc in self._procs:
            await self._proc_kill(proc)
       self._procs = []

# ----------------------------------------
    async def send_mesg(self, host="localhost", port=8080, mesg=""):
        ret = ""
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((host, port))
            s.sendall(str.encode(mesg))
            data = s.recv(1024)
            ret = data.decode("utf-8")

        return ret
