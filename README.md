# parallel_prog
OpenMP and Julia Code for Parallel Programming Course Work

# Notes / ToDos

I ran the code on an ubuntu VM through virtualbox. if you choose to take that route, make sure you set the number of processors to use in virtualbox higher than 1, or else env vars for num threads won't work for openmp or julia.

About the code, parallelization with threads worked, but what was interesting was that loop interchange was slower for julia. maybe it uses it's own optimizations so people don't mess around? Also indexing starts at 1 rather than 0 in julia.The majority of the work will probably be in researching julia uses

https://www.quora.com/What-are-some-good-uses-for-the-Julia-programming-language

https://juliacomputing.com/case-studies/ julia's multi-threading support

https://docs.julialang.org/en/v1/manual/parallel-computing/

https://en.wikipedia.org/wiki/Loop_interchange 
