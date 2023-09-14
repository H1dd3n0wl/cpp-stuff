import os
import argparse
from pathlib import Path


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "destination",
        choices=["graphs", "ds", "strings", "math"],
        help="folder where to create the algo",
    )
    parser.add_argument(
        "name", help="the name of the algo, also the name of the folder where it"
    )

    args = parser.parse_args()

    path = Path.cwd().joinpath("algorithms").joinpath(args.destination)

    if not path.exists():
        path.mkdir()

    path = path.joinpath(args.name)

    if not path.exists():
        path.mkdir()

    path.joinpath(args.name + ".hpp").touch(exist_ok=True)

    cmakelist = path.joinpath("CMakeLists.txt").open("w")
    cmakelist.writelines(
        [
            "add_executable({} test_{}.cpp)\n".format(args.name, args.name),
            "target_link_libraries({} ${{GTEST_LIBRARIES}} pthread)\n\n".format(
                args.name
            ),
            "add_test(NAME {}_test COMMAND {})".format(args.name, args.name),
        ]
    )
    cmakelist.close()

    test_file = path.joinpath("test_" + args.name + ".cpp").open("w")
    test_file.writelines(
        [
            "#include <gtest/gtest.h>\n",
            '#include "{}.hpp"\n\n'.format(args.name),
            "TEST({}, {}) {{\n".format(args.name, args.destination),
            "\tASSERT_EQ(1, 1);\n",
            "}\n\n",
            "int main(int argc, char **argv) {\n",
            "\ttesting::InitGoogleTest(&argc, argv);\n",
            "\treturn RUN_ALL_TESTS();\n}",
        ]
    )
    test_file.close()

    append_cmake = Path.cwd().joinpath("CMakeLists.txt").open("a")
    append_cmake.write(
        '\nadd_subdirectory("{}")'.format(
            "algorithms/" + args.destination + "/" + args.name
        )
    )
    append_cmake.close()


main()
