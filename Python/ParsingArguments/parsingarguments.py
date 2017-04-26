import sys, argparse

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--x', type=float, default=2.0, help="1st Number?")
    parser.add_argument('--y', type=float, default=2.0, help="2nd Number?")
    parser.add_argument('--operation', type=str, default='add', help="What Operation(add,sub,mul,div)")
    args = parser.parse_args()
    sys.stdout.write(str(calc(args)))

def calc(args):
    if(args.operation == 'add'):
        return args.x + args.y
    elif(args.operation == 'sub'):
        return args.x - args.y
    elif (args.operation == 'mul'):
        return args.x * args.y
    elif (args.operation == 'div'):
        return args.x / args.y

main()
