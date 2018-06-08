#! /usr/bin/env lua

io.write[[
HTTP/1.1 200 OK
Content-Type: text/plain; charset=UTF-8

1
]]
io.flush()

os.execute "sleep 0.33"
io.write "2\n"
io.flush()

os.execute "sleep 0.33"
io.write "3\n"
io.flush()

os.execute "sleep 0.33"
io.write "4\n"
