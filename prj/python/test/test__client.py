""" Client tests """
import time

from src._client import Client
from src._man_file import ManFile

import asyncio
import pytest

# ---------------------------------------------------------
@pytest.mark.asyncio
async def test_multiple_cpp_procs():
    """ test multiple connections - can work for db (persisted on disk) store only
    since the in memory stores are (by defintion) not persistent
    """
    c = Client()

    my_exec = ManFile.file_path_exec()
    # my_exec2 = "/Users/declan/Documents/zone/high/dev/mysql/prj/build-app-Qt_6_4_2_for_macOS-Debug/mysql_main"
    ret_vals = await asyncio.gather(
        c.proc_start(my_exec, args=["--port", "8086"]),
        c.proc_start(my_exec, args=["--port", "8087"])
    )


    # give servers chance to start
    await asyncio.sleep(1)

    name0 = "jim"
    name1 = "mary"
   # await asyncio.gather(
    await c.send_mesg(host="localhost", port=8086, mesg=f"Write, 15, {name0}"),
    await c.send_mesg(host="localhost", port=8087, mesg=f"Write, 16, {name1}")
   # )

    ret = await asyncio.gather(
        c.send_mesg(host="localhost", port=8086, mesg="Read, 16"),
        c.send_mesg(host="localhost", port=8087, mesg="Read, 15")
    )

    print("c++ instance 2 reads back value written by instance 1...")
    assert(ret[0] == name1)

    # and vice versa
    print("c++ instance 1 reads back value written by instance 2...")
    assert (ret[1] == name0)

    await c.procs_kill()
# ---------------------------------------------------------
@pytest.mark.asyncio
async def test_one_cpp_proc():
    """ test single connection. Will work for in memory store and db (persisted on disk) """

    c = Client()

    my_exec = ManFile.file_path_exec()
    ret = await c.proc_start(my_exec, args=["--port", "8086"]),
    print(f"main_one.....proc_start : {ret}")

    # give server chance to start
    await asyncio.sleep(1)

    name = "jon"
    await c.send_mesg(host="localhost", port=8086, mesg=f"Write, 15, {name}")
    ret = await c.send_mesg(host="localhost", port=8086, mesg="Read, 15")
    assert ret == name

    await c.procs_kill()

    halt =1
