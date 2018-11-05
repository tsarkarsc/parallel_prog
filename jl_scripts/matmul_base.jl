N = 512

function matmul(a, b, c, n)
    for i = 1:n
        for j = 1:n
            for k = 1:n
                c[i,j] += a[i,k] * b[k,j]
            end
        end
    end

    return c
end 

function checksum(x)
    sum = 0.0

    for i = 1:N
        for j = 1:N
            sum += x[i,j]
        end
    end

    return sum
end

# creates and returns 2d array of zeroes
function initialize()
    a = zeros(Float64, N, N)

    for i = 1:N
        for j = 1:N
            a[i,j] = (convert(Float64,((i-1) * (j-1))) / convert(Float64, (N * N)))
        end
    end

    return a
end

a = initialize();
b = initialize();
c = initialize();

start_t = time()

d = matmul(a, b, c, N)

end_t = time()
run_time = end_t - start_t

sum = checksum(d)

println("checksum = $sum")

println("matmul func time (s):")
println(run_time)
