import sys
sys.path.insert(0,'D:/Installations/Anaconda/Installed/envs/CoAP/Scripts')
from coapthon.server.coap import CoAP
from exampleresources import BasicResource
from coapthon.resources.resource import Resource
import json
from coapthon import defines


class data(Resource):
    def __init__(self,name="data",coap_server=None):
    	super(data, self).__init__(name)

        self.value = 0
        self.payload = str(self.value)
        self.content_type = [defines.Content_types["application/json"]]
        self.payload = (defines.Content_types["application/json"], "{'name': '"+str(self.value)+"', 'data': '"+str(self.value)+"', 'accesstoken': '"+str(self.value)+"' }")

    def render_GET(self, request):
        return self


class CoAPServer(CoAP):
    def __init__(self, host, port, multicast=False):
        CoAP.__init__(self, (host, port))
        self.add_resource('basic/', data())


def main():
    server = CoAPServer("0.0.0.0", 5683, False)
    try:
        server.listen(10)
        print "executed after listen"
    except KeyboardInterrupt:
        print "Server Shutdown"
        server.close()
        print "Exiting..."

if __name__ == '__main__':
    main()