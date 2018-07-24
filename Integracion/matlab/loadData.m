function [ A ] = loadData( path )
filename = path;
delimiterIn = ' ';
A = importdata(filename,delimiterIn);
end

