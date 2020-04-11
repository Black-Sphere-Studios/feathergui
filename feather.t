local Backend = require 'feather.backend'
local Test = require 'feather.test'
local Export = require 'feather.c-headers'
local Shared = require 'feather.shared'

if terralib.saveobj("bin-"..jit.arch.."/feather.exe", {main = Test.main}) ~= nil then
  return -1
end

Test.main(0, nil)

local transfer = {"Vec","URect","Rect","Delegate","UVec","Color","Veci","Color16","Vec3D"}
for i,k in ipairs(transfer) do
  Backend[k] = Shared[k]
end

local f = io.open("backend.h", "wb")
f:write(Export({short_name="FG", long_name="BACKEND"}, Backend))

return 0