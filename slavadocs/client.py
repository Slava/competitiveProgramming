from requests import post
from optparse import OptionParser

if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option('--host', dest='hostname', default='localhost:8888')

    (options, args) = parser.parse_args()
    hostname = 'http://' + options.hostname

    while True:
        try:
            line = raw_input()
        except EOFError:
            break

        post(hostname, data = {'method' : 'type', 'message' : line})

    post(hostname, data = {'method' : 'command', 'message' : 'clear'})

