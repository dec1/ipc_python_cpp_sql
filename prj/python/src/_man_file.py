""" see ManFile below """

import os


class ManFile:
    """ Provides file and directory (path) services and lookup."""
    # ---------------------------------------------------------
    @classmethod
    def file_path_exec(cls) -> str:
        """  (abs) path of c++ executable app """
        # "/Users/declan/Documents/zone/high/dev/mysql/prj/script/app/build/mysql_main"
        return cls.full_path(rel_path="my_app_main", root_path=cls.dir_path_build())

    # ---------------------------------------------------------
    @classmethod
    def dir_path_root(cls) -> str:
        """ root dir (abs) path of python project - contains 'prj', 'src', 'script' ... """
        dir_path_parent = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        return dir_path_parent
    # ---------------------------------------------------------
    @classmethod
    def full_path(cls, rel_path: str, root_path: str = None):
        """ full path of 'rel_path' within 'root_path """

        if root_path is None:
            root_path = cls.dir_path_root()

        ret = os.path.join(root_path, rel_path)
        return ret

    # ---------------------------------------------------------
    @classmethod
    def dir_path_build(cls) -> str:
        """  (abs) path of c++ executable projec """
        return cls.full_path(rel_path="../cpp/build", root_path=cls.dir_path_root())



    # ---------------------------------------------------------
