
from ._client import Client
from ._man_file import ManFile
import asyncio

# ------------------------------------
async def main_one():
   c = Client()


   my_exec = ManFile.file_path_exec()
   ret = await c.proc_start(my_exec, args=["--port", "8086"]),
   print(f"main_one.....proc_start : {ret}")

   # give server chance to start
   await asyncio.sleep(1)

   ret1 = await c.send_mesg(host="localhost", port=8086, mesg="Write, 15, John")
   ret2 = await c.send_mesg(host="localhost", port=8086, mesg="Read, 15")
   print(f"main_one.....: {ret2}")
   await c.procs_kill()

   for elem in ret:
      print(elem)
# ------------------------------------
async def main():

   c = Client()

   #my_exec = "/Users/declan/Documents/zone/high/dev/mysql/prj/build-app-Qt_6_4_2_for_macOS-Debug/mysql_main"
   my_exec = ManFile.file_path_exec()
   ret_vals = await asyncio.gather(
      c.proc_start(my_exec, args=["--port", "8086"]),
      c.proc_start(my_exec, args=["--port", "8087"])
   )

   # give servers chance to start
   await asyncio.sleep(1)

   rets1 = await asyncio.gather(
      c.send_mesg(host="localhost", port=8086, mesg="Write, 15, John"),
      c.send_mesg(host="localhost", port=8087, mesg="Write, 16, Mary")
   )

   rets2 = await asyncio.gather(
      c.send_mesg(host="localhost", port=8086, mesg="Read, 16"),
      c.send_mesg(host="localhost", port=8087, mesg="Write, 15")
   )

   await c.procs_kill()

   for elem in rets2:
      print(elem)


if __name__ == "__main__":
   asyncio.run(main_one())
   halt =1
