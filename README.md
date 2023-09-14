## Tutorial for adding algorithms


First, run the command below and provide type of algorithm and it's name, for example eratosthenes algorithm is from math scope.

```sh
$ python3 ./tools/algo_template [type] [name]
```

After the script creates the files, go to `[name].hpp` file in `algorithms/[type]/` folder and write your algorithm.

You also can add a test (some task that uses this algorithm) in `test_[name].cpp` file in function `TEST(...) {}` but it is optional.